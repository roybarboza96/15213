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

#define WSIZE 8   /* word and header/footer size */
#define DSIZE 16   /* doubleword size */
#define CHUNKSIZE (1<<12)   /* extend heap by this amount */


#define MAX(x,y) ((x) > (y)? (x) : (y))


/* Pack a size and allocated bit into a word */
#define PACK(size,alloc) ((size) | (alloc))


/*  Read and write a word a address p */
#define GET(p)       (*(unsigned int *)(p))
#define PUT(p,val)   (*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from addresss p */
#define GET_SIZE(p)    (GET(p) & ~0x7)
#define GET_ALLOC(p)   (GET(p) & 0x1)


/* Given block ptr pb, compute address of its header and footer */
inline char* HDRP(void *bp)
{
   return ((char *)(bp) - WSIZE);
}
inline char* FTRP(void *bp)
{
   return ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE);
}

/* given block ptr bp, compute address of next and previous blocks */
inline char* NEXT_BLKP(void *bp)
{
   return ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)));
}
inline char* PREV_BLKP(void *bp)
{
   return ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)));
}

inline void * PRED(void *bp)
{
   return bp;
}

inline void * SUC(void *bp)
{
   return bp + DSIZE;
}

inline void * ADDRESS(char * list)
{
   return (void *)list;
}

static void *find_fit(size_t asize);
static void *coalesce(void *ptr);
static void place(void *ptr, size_t asize);
static void *extend_heap(size_t words);
static void printblock(void *bp);
static void checkheap(int verbose);
static void checkblock(void *bp);



static char *heap_listp = 0;  /* Pointer to first block */

static char *free_endp = 0; /* Pointer to end of free block */

static char *rover;


/*
 * Initialize: return -1 on error, 0 on success.
 */
int mm_init(void) {

    if ( (heap_listp = mem_sbrk(4*WSIZE)) == (void *) -1)
       return -1;


    PUT(heap_listp,0);                           /* Alignment padding */

    PUT(heap_listp + (1*WSIZE), PACK(DSIZE,1));  /* Prologue header */

/*

    PUT(heap_listp + (2*WSIZE), PACK(0,0));       Prologue successor 

    PUT(heap_listp + (4*WSIZE), PACK(0,0));      Prologue predecssor 
*/    

    PUT(heap_listp + (2*WSIZE), PACK(DSIZE,1));  /* Prologue footer */

    PUT(heap_listp + (3*WSIZE), PACK(0,1));      /* epilogue header */




    heap_listp += (2*WSIZE);

    /* heap_listp += (2*DSIZE);  */

    free_endp = heap_listp;

    rover = heap_listp;

    if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
       return -1;

    rover = free_endp; 

    return 0;
}

/*
 * malloc
 */
void *malloc (size_t size) 
{
    size_t asize;      /* block size */
    size_t extendsize;   /* Amount to extend heap if no fit */
    char *bp;   


    /* intial settings. No heap thus need to create it */   
    if (heap_listp == 0) {
        mm_init();
    }


    /* if the size is 0, then just do nothing and return NULL */
    if (size == 0)
        return NULL;


    /* adjust block size to include overhead and alignment reqs */
    if (size <= DSIZE)
        asize = 4*DSIZE;
    else
        asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE);

 /* To include the predecssor and successor addresses */
 /*   asize += 2*DSIZE;  */


    printf("it got past mm_init\n");


    /* search the free list for a fit */
    if ((bp = find_fit(asize)) != NULL)
    {
       printf("it found a fit\n");
       place(bp,asize);
       return bp;
    }

    printf("it got past find fit\n");

    /* If not fit was found. Get more memory and place the block */
    
    extendsize = MAX(asize,CHUNKSIZE);

    if ((bp = extend_heap(extendsize/WSIZE)) == NULL)
       return NULL;


    place(bp,asize);
    return bp;

    

}

/*
 * free - Frees the block of memory that is pointed by ptr
 */
void free (void *ptr) 
{

    if(!ptr) return;

    size_t size = GET_SIZE(HDRP(ptr));

    if (heap_listp == 0) {
       mm_init();
    }


    PUT(HDRP(ptr),PACK(size,0));
    PUT(FTRP(ptr),PACK(size,0));
    coalesce(ptr);
}

/*
 *
 * coalesce
 */
static void *coalesce(void *ptr)
{
   size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(ptr)));
   size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));
   size_t size = GET_SIZE(HDRP(ptr));


   /* if previous and next block is allocated then can't coalesce */
   if (prev_alloc && next_alloc)
   {
      return ptr;
   }
   /* if only the previous block is allocated */
   else if (prev_alloc && !next_alloc)
   {

      size += GET_SIZE(HDRP(NEXT_BLKP(ptr)));
      PUT(HDRP(ptr), PACK(size, 0));
      PUT(FTRP(ptr), PACK(size, 0));


     
      PUT(PRED(ptr),(long unsigned int)PRED(NEXT_BLKP(ptr)));
      PUT(SUC(ptr), (long unsigned int)SUC(NEXT_BLKP(ptr)));


   }
   /* if the only the next block is allocated */
   else if (!prev_alloc && next_alloc)
   {

      size += GET_SIZE(HDRP(PREV_BLKP(ptr)));
      PUT(FTRP(ptr), PACK(size, 0));
      PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));

      /* 
 *    
 *
 */

      ptr = PREV_BLKP(ptr);
   
   } 
   /* if both the next block and previous block are free */
   else
   {

       size += GET_SIZE(HDRP(PREV_BLKP(ptr))) 
                     + GET_SIZE(FTRP(NEXT_BLKP(ptr)));

       PUT(HDRP(PREV_BLKP(ptr)), PACK(size, 0));
       PUT(FTRP(NEXT_BLKP(ptr)), PACK(size, 0));

       PUT(SUC(PREV_BLKP(ptr)), (long unsigned int)SUC(NEXT_BLKP(ptr)));


       ptr = PREV_BLKP(ptr);
   }

   if ((rover > (char *)ptr) && (rover < NEXT_BLKP(ptr)))
      rover = ptr;

   return ptr;

}


/*
 * realloc - you may want to look at mm-naive.c
 */
void *realloc(void *oldptr, size_t size) 
{
    size_t oldsize;
    void *newptr;


    /* If size == 0 then this is just free and return NULL */
    if(size == 0) {
       free(oldptr);
       return 0;
    }


    /* If oldptr is NULL, then this is just malloc. */
    if(oldptr == NULL) {
       return malloc(size);
    }


    newptr = malloc(size);

    /* if realloc fails the original block is untouched */
    if (!newptr) {
       return 0;
    }


    /* Copy the old data */
    oldsize = GET_SIZE(HDRP(oldptr));
    if(size < oldsize)
      oldsize = size;
    memcpy(newptr, oldptr, oldsize);


    /* Free the old block */
    free(oldptr);


   return newptr;

}

/*
 * calloc - you may want to look at mm-naive.c
 * This function is not tested by mdriver, but it is
 * needed to run the traces.
 */
void *calloc (size_t nmemb, size_t size) 
{

    size_t bytes = nmemb * size;
    void *newptr;

    newptr = malloc(bytes);
    memset(newptr, 0 , bytes);
   
    return newptr;
}


static void *extend_heap(size_t words)
{
    char *bp;
    size_t size;

    /* Allocate an even number of words to maintain alignment */
    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;

    if ((long)(bp = mem_sbrk(size)) == -1)
       return NULL;

    /* Initialize free block header/footer and the epilogue header */
    PUT(HDRP(bp),PACK(size, 0));              /* free block header */
    PUT(FTRP(bp),PACK(size, 0));              /* free block footer */



    PUT(PRED(bp), (long int)(free_endp));
    PUT(SUC(bp), 0);

    free_endp = bp;  

    PUT(HDRP(NEXT_BLKP(bp)), PACK(0,1));      /* new epilogue header */


    /* Coalesce if the previous block was free */
    return coalesce(bp);


}



/*
 *
 * place - Place block of asize bytes at start of free block bp
 *         and split if remainder would be at least minimum block size
 *
 */

static void place(void *bp, size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));

/*  has to change to 4*DSIZE to make room for pointers  */


    if ((csize - asize) >= (4*DSIZE))
    {

       PUT(HDRP(bp), PACK(asize,1));
       PUT(FTRP(bp), PACK(asize,1));

       unsigned int intial = (long unsigned int)GET_SIZE(HDRP(bp));
       printf("the header   : %x\n",(unsigned int)asize);
       printf("the inital bp: %x\n",intial);

       

       bp = NEXT_BLKP(bp);
       PUT(HDRP(bp), PACK(csize-asize, 0));


       unsigned int hd = (long unsigned int)*HDRP(bp);

       printf("the free block header: %x\n",hd);

       PUT(SUC(free_endp), (long int)(bp));
       PUT(PRED(bp), (long int)(free_endp) );
       PUT(SUC(bp), 0);


       free_endp = bp;


//       printf("the csize %d\n",(unsigned int)csize);
 //      printf("the asize %d\n",(unsigned int)asize);
 //      printf("the csize-asize %d\n",(unsigned int)(csize -asize));
       unsigned int test = (long unsigned int)*FTRP(bp);

    

       printf("%x\n",test);

       PUT(FTRP(bp), PACK(csize-asize, 0));
       printf("after the put\n");

    }
    else
    {

       PUT(HDRP(bp), PACK(csize, 1));
       PUT(FTRP(bp), PACK(csize, 1));

    }

}

/*
 *
 * find_fit - Find a fit for a block with asize bytes
 *
 */
static void *find_fit(size_t asize)
{
    char *oldrover = rover;
/*
     search from the rover to the end of the list 
    for ( ; GET_SIZE(HDRP(rover)) > 0; rover = NEXT_BLKP(rover))
        if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
           return rover;


     search from start of list to old rover 
    for (rover = heap_listp; rover < oldrover; rover = NEXT_BLKP(rover))
        if (!GET_ALLOC(HDRP(rover)) && (asize <= GET_SIZE(HDRP(rover))))
           return rover;


    return NULL;  no fit found 
*/
 
    for ( ; ((long unsigned int)rover)  > 0 ; rover = SUC(rover))
        if ( asize <= GET_SIZE(HDRP(rover)))
           return rover;


    for (rover = heap_listp; rover < oldrover; rover = SUC(rover))
        if ( asize <= GET_SIZE(HDRP(rover)))
           return rover;


   return NULL;


}

static void printblock(void *bp)
{
     size_t hsize, halloc, fsize, falloc;

     checkheap(0);
     hsize = GET_SIZE(HDRP(bp));
     halloc = GET_ALLOC(HDRP(bp));
     fsize = GET_SIZE(FTRP(bp));
     falloc = GET_ALLOC(FTRP(bp));


     if (hsize == 0)
     {
        printf("%p, EOL\n", bp);
        return;
     }

/*     printf("%p: header: [%p:%c] footer: [%p:%c]\n"
           , bp
           , hsize, (halloc ? 'a' : 'f')
           , fsize, (falloc ? 'a' : 'f'));
*/

}

static void checkblock(void *bp)
{

    if ((size_t)bp % 8)
       printf("Error: %p is not doubleword aligned\n", bp);
/*    if ( in_heap(bp) == 0)
       printf("Error: %p is not in the heap\n",bp);
    if ( aligned(bp) == 0)
       printf("Errro: %p is not algined correctly\n",bp);
*/
    if (GET(HDRP(bp)) != GET(FTRP(bp)))
       printf("Error: header does not match footer\n");

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
static void checkheap(int verbose) 
{

   char *bp = heap_listp;


   if (verbose)
      printf("Heap (%p):\n", heap_listp);


   if ((GET_SIZE(HDRP(heap_listp)) != DSIZE) || !GET_ALLOC(HDRP(heap_listp)))
      printf("Bad Prologue header\n");
   checkblock(heap_listp);

   

   for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp))
   {
       if (verbose)
          printblock(bp);
       checkblock(bp);
       in_heap(bp);
       aligned(bp); 
   }

   if (verbose)
      printblock(bp);
   if ((GET_SIZE(HDRP(bp)) != 0 || !(GET_ALLOC(HDRP(bp)))))
      printf("Bad epilogue header\n");


}


void mm_checkheap(int lineno)
{

     lineno = lineno;


}
