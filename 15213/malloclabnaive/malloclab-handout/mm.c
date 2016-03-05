/*
 * mm.c
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mm.h"
#include "memlib.h"

/* If you want debugging output, use the following macro.  When you hand
 * in, remove the #define DEBUG line. */
#define DEBUG
#ifdef DEBUG
# define dbg_printf(...) printf(__VA_ARGS__)
#else
# define dbg_printf(...)
#endif


/* do not change the following! */
#ifdef DRIVER
/* create aliases for driver tests */
#define malloc mm_malloc
#define free mm_free
#define realloc mm_realloc
#define calloc mm_calloc
#endif /* def DRIVER */

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(p) (((size_t)(p) + (ALIGNMENT-1)) & ~0x7)

/* $begin mallocmacros */
/* Basic constants and macros */
#define WSIZE       8       /* Word and header/footer size (bytes) */
#define DSIZE       16       /* Doubleword size (bytes) */
#define CHUNKSIZE  (1<<10)  /* Extend heap by this amount (bytes) */  

#define MAX(x, y) ((x) > (y)? (x) : (y))  

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)  ((size) | (alloc)) 

/* Read and write a word at address p */
#define GET(p)       (*(unsigned long int *)(p))          
#define PUT(p, val)  (*(unsigned long int *)(p) = (val))    

/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)                 
#define GET_ALLOC(p) (GET(p) & 0x1)                    

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)       ((char *)(bp) - WSIZE)                      
#define FTRP(bp)       ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE) 

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) 
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE))) 
/* $end mallocmacros */

inline char* PRED(void *bp)
{
    return bp;
}

inline char* SUC(void *bp)
{
    return bp + WSIZE;
}
inline char *PRED_ADD(void *bp)
{
    return (char *)GET(PRED(bp));
}
inline char *SUC_ADD(void *bp)
{
    return  (char *)GET(SUC(bp));
}
/* Global variables */
static char *heap_listp = 0;  /* Pointer to first block */  

static char *rover;           /* Next fit rover */

static char *free_startp = 0;

static char *heap_startp = 0;




/* Function prototypes for internal helper routines */
static void *extend_heap(size_t words);
static void place(void *bp, size_t asize);
static void *find_fit(size_t asize);
static void *coalesce(void *bp);
static void printblock(void *bp); 
static void checkheap(int verbose);
static void checkblock(void *bp);
static void skip(void *bp);
static void insert(void *bp);
static void printExp(int verbose);
/*
 * Initialize: return -1 on error, 0 on success.
 */
int mm_init(void) 
{
   if ((heap_listp = mem_sbrk(6*WSIZE)) == (void *)-1)
	return -1;

    PUT(heap_listp, 0);                          /* Alignment padding */

    PUT(heap_listp + (1*WSIZE), PACK(2*DSIZE, 1)); /* Prologue header */ 

    PUT(heap_listp + (2*WSIZE), 0);
    PUT(heap_listp + (3*WSIZE), 0);

    PUT(heap_listp + (4*WSIZE), PACK(2*DSIZE, 1)); /* Prologue footer */ 

    PUT(heap_listp + (5*WSIZE), PACK(4*WSIZE, 1));     /* Epilogue header */




    heap_listp += (2*WSIZE);                     

    rover = heap_listp;

    free_startp = heap_listp;

    heap_startp = heap_listp;

    void * firstfree;

    /* Extend the empty heap with a free block of CHUNKSIZE bytes */
    if ((firstfree = extend_heap(CHUNKSIZE/WSIZE)) == NULL) 
	return -1;

    /* with that free block that is returned add that to our new list
 *     only works for the initial settings */

    PUT(PRED(firstfree),(unsigned long int)heap_startp);
    PUT(SUC(firstfree),(unsigned long int)heap_startp);


    free_startp = firstfree;      /* boundry free block */

    rover = free_startp;

    
    return 0;
}

/*
 * malloc
 */
void *malloc (size_t size) 
{

    size_t asize;      /* Adjusted block size */
    size_t extendsize; /* Amount to extend heap if no fit */
    char *bp;      



    if (heap_listp == 0){
	mm_init();
    }
 
    /* Ignore spurious requests */
    if (size == 0)
	return NULL;


    /* Adjust block size to include overhead and alignment reqs. */
    if (size <= WSIZE)                                          
	asize = 2*DSIZE;                                        
    else
	asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE); 



    /* Search the free list for a fit */
    if ((bp = find_fit(asize)) != NULL) {  
	place(bp, asize);                 
	return bp;
    }

    /* No fit found. Get more memory and place the block */
    extendsize = MAX(asize,CHUNKSIZE);                 
    if ((bp = extend_heap(extendsize/WSIZE)) == NULL)  
	return NULL; 
    place(bp, asize);                                
    return bp;

}

/*
 * free
 */
void free (void *bp) 
{

    if(bp == 0) 
	return;

    size_t size = GET_SIZE(HDRP(bp));


//    printf("FREEING\n");
    if (heap_listp == 0){
	mm_init();
    }

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));


    insert(bp);
    coalesce(bp);



}




/*
 *  * coalesce - Boundary tag coalescing. Return ptr to coalesced block
 *   */
static void *coalesce(void *bp) 
{

    size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));

    size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));

    size_t size = GET_SIZE(HDRP(bp));

    if (prev_alloc && next_alloc) 
    {            /* Case 1 */
	return bp;
    }
    /*  if the the next block is free  */
    else if (prev_alloc && !next_alloc) 
    {      /* Case 2 */

	size += GET_SIZE(HDRP(NEXT_BLKP(bp)));

        skip(NEXT_BLKP(bp));

	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size,0));
     

    }
    /* if the previous block is free */
    else if (!prev_alloc && next_alloc) 
    {      /* Case 3 */
	size += GET_SIZE(HDRP(PREV_BLKP(bp)));

        skip(PREV_BLKP(bp));
        insert(PREV_BLKP(bp));
        skip(bp);

	PUT(FTRP(bp), PACK(size, 0));
	PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));


	bp = PREV_BLKP(bp);
    }
    /* if both the previous and next block are free */
    else 
    {                               
	size += GET_SIZE(HDRP(PREV_BLKP(bp))) + 
	    GET_SIZE(FTRP(NEXT_BLKP(bp)));

        skip(PREV_BLKP(bp));
        insert(PREV_BLKP(bp));
        skip(bp);
        skip(NEXT_BLKP(bp));

	PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
	PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));

	bp = PREV_BLKP(bp);

    }


    /* Make sure the rover isn't pointing into the free block */
    /* that we just coalesced */
//    if ((rover > (char *)bp) && (rover < NEXT_BLKP(bp))) 
//	rover = bp;



    return bp;
}




/*
 * realloc - you may want to look at mm-naive.c
 */
void *realloc(void *ptr, size_t size) {
    size_t oldsize;
    void *newptr;


    /* If size == 0 then this is just free, and we return NULL. */
    if(size == 0) {
	free(ptr);
	return 0;
    }

    /* If oldptr is NULL, then this is just malloc. */
    if(ptr == NULL) {
	return malloc(size);
    }

    newptr = malloc(size);

    /* If realloc() fails the original block is left untouched  */
    if(!newptr) {
	return 0;
    }

    /* Copy the old data. */
    oldsize = GET_SIZE(HDRP(ptr));
    if(size < oldsize) oldsize = size;
    memcpy(newptr, ptr, oldsize);

    /* Free the old block. */
    free(ptr);

    return newptr;
}

/*
 * calloc - you may want to look at mm-naive.c
 * This function is not tested by mdriver, but it is
 * needed to run the traces.
 */
void *calloc (size_t nmemb, size_t size) {
    size_t bytes = nmemb * size;
    void *newptr;

    newptr = malloc(bytes);
    memset(newptr, 0 , bytes);


    return newptr;
}



/* 
 *  * extend_heap - Extend heap with free block and return its block pointer
 *   */
static void *extend_heap(size_t words) 
{

    char *bp;
    size_t size;


    /* Allocate an even number of words to maintain alignment */
    size = (words % 2) ? (words+1) * WSIZE : words * WSIZE; 
    if ((long)(bp = mem_sbrk(size)) == -1)  
	return NULL;                                    


    /* Initialize free block header/footer and the epilogue header */
    PUT(HDRP(bp), PACK(size, 0));         /* Free block header */   
    PUT(FTRP(bp), PACK(size, 0));         /* Free block footer */   


    insert(bp);

    printExp(1);
    
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header */ 


    /* Coalesce if the previous block was free */
    return coalesce(bp);     
                                
}




/* 
 * insert - insert free block at the front of the list
 */
static void insert(void *bp)
{
    PUT(SUC(bp), (unsigned long int)free_startp);
    PUT(PRED(bp),(unsigned long int)heap_startp);
    PUT(PRED(free_startp),(unsigned long int)bp);
    free_startp = bp;
}









/* 
 *  * place - Place block of asize bytes at start of free block bp 
 *   *         and split if remainder would be at least minimum block size
 *    */
static void place(void *bp, size_t asize)
{

    size_t csize = GET_SIZE(HDRP(bp));   

    void *nbp = NEXT_BLKP(bp);
 //   checkheap(1);

    if ((csize - asize) >= (4*DSIZE)) 
    {

	PUT(HDRP(bp), PACK(asize, 1));
	PUT(FTRP(bp), PACK(asize, 1));

	nbp = NEXT_BLKP(bp);

	PUT(HDRP(nbp), PACK(csize-asize, 0));
	PUT(FTRP(nbp), PACK(csize-asize, 0));

        insert(nbp);


        skip(bp);

    }
    else 
    { 
	PUT(HDRP(bp), PACK(csize, 1));
	PUT(FTRP(bp), PACK(csize, 1));
        skip(bp);
    }
}


/*
 *
 * skip - remove element from explicit list
 */
static void skip(void *bp)
{


   if (free_startp != bp)
   {

      PUT( PRED(SUC_ADD(bp)) , GET(PRED(bp)) );
      PUT( SUC(PRED_ADD(bp)), GET(SUC(bp)) );
   }
   else
   {
      free_startp = SUC_ADD(bp);
      PUT(PRED(free_startp),(unsigned long int)heap_startp);
   }


}

/* 
 *  * find_fit - Find a fit for a block with asize bytes 
 *   */
static void *find_fit(size_t asize)
{
// char * oldrover = rover;

  
    rover = free_startp;
    for( ; rover != heap_startp; rover = SUC_ADD(rover) )
    {
       if ( asize <= GET_SIZE(HDRP(rover)))
       {
          return rover;
       }

       
    }
/*
   for(rover = free_startp; rover < oldrover; rover = SUC_ADD(rover))
   {
       if ( GET_ALLOC(HDRP(rover)) == 1)
          printf("ERROR going into already allocated memory\n");
       if ( asize <= GET_SIZE(HDRP(rover)))
       {
          return rover;
       }


   }
*/
    return NULL;

}



/*
 *
 * printExp - print out contents of explicit list
 *            useful for debugging
 */
static void printExp(int verbose)
{

    if( verbose > 0)
      return;

    char *tmp = free_startp;
    
    printf("all the current blocks in our list\n");
    for( ; tmp != heap_startp; tmp = SUC_ADD(tmp) )
    {
       printf("ADDRESS:%p, ",tmp);
       printf("SIZE: %lu, ",GET_SIZE(HDRP(tmp)));
       printf("PRED: %lx, ",GET(PRED(tmp)));
       printf("SUC: %lx\n", GET(SUC(tmp)));
    }

    printf("\n");
 

}



/*
 * Return whether the pointer is in the heap.
 * May be useful for debugging.
 */
static int in_heap(const void *p) {
    return p <= mem_heap_hi() && p >= mem_heap_lo();
}

/*
 * Return whether the pointer is aligned.
 * May be useful for debugging.
 */
static int aligned(const void *p) {
    return (size_t)ALIGN(p) == (size_t)p;
}

/*
 * mm_checkheap
 */
void mm_checkheap(int lineno) 
{
lineno = lineno;

}

static void printblock(void *bp) 
{
    size_t hsize, halloc, fsize, falloc;

    checkheap(0);
    hsize = GET_SIZE(HDRP(bp));
    halloc = GET_ALLOC(HDRP(bp));  
    fsize = GET_SIZE(FTRP(bp));
    falloc = GET_ALLOC(FTRP(bp));  

    if (hsize == 0) {
	printf("%p: EOL\n", bp);
	return;
    }

    /*  printf("%p: header: [%p:%c] footer: [%p:%c]\n", bp, 
 *  	hsize, (halloc ? 'a' : 'f'), 
 *  		fsize, (falloc ? 'a' : 'f')); */
}

static void checkblock(void *bp) 
{
    if ((size_t)bp % 8)
	printf("Error: %p is not doubleword aligned\n", bp);
    if (GET(HDRP(bp)) != GET(FTRP(bp)))
	printf("Error: header does not match footer\n");
}

/* 
 *  * checkheap - Minimal check of the heap for consistency 
 *   */
void checkheap(int verbose) 
{
    char *bp = heap_listp;

    if (verbose)
	printf("Heap (%p):\n", heap_listp);

    if ((GET_SIZE(HDRP(heap_listp)) != 2*DSIZE) || !GET_ALLOC(HDRP(heap_listp)))
	printf("Bad prologue header\n");
    checkblock(heap_listp);

    for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
	if (verbose) 
	    printblock(bp);
	checkblock(bp);
        in_heap(bp);
        aligned(bp);
    }

    if (verbose)
	printblock(bp);
    if ((GET_SIZE(HDRP(bp)) != 0) || !(GET_ALLOC(HDRP(bp))))
	printf("Bad epilogue header\n");
}


