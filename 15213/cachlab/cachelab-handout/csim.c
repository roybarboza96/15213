/****************************************************************************
 *Roy Sung
 *rsung
 *
 * Everything is all in the main function. It is written sequentially and is
 * broken up by comments
 *
 * **************************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>
#include "cachelab.h"




int main (int argc, char **argv)
{

  int e = -1;   /* # of lines per set */


  int s = -1;   /* # of set bits, thus 2^s = # of sets */
  int sbig = -1;

  int b = -1;   /* # of block bits, 2^b = block size(bytes)   */
  int bbig = -1;

  int verbose = 0;  /* indicator value for the print function */
  FILE *fp = NULL;  /* trace file */

  int i;
  int j;

  int c;

  while( (c = getopt(argc,argv,"s:E:b:t:v::h::") ) != -1)
  {

    switch(c)
    {

      case 's':

        s = atoi(optarg);
        sbig = pow(2,s);
        break;

      case 'E':

        e = atoi(optarg);
        break;

      case 'b':

        b = atoi(optarg);
        bbig = pow(2,b);
        break;

      case 't':

        fp = fopen(optarg,"r");
        break;

      case 'v':

        verbose = 1;
        break;

      case 'h': 

        printf("This is just a test\n");
        exit(0);
        break;

      case '?':

         if( optopt == 's' || optopt == 'E' || optopt == 'b' || optopt == 't')
            printf("Missing argument for  %c option\n",optopt);
         else
            printf ("Unknown option %c\n ",optopt);

         exit(0);
         break;
  

    } 
  }

  if( b == -1 || e == -1 || s == -1) {
    printf("Missing required arguments for b,s,e, these are needed run this" 
            " program properly\n");
    exit(0);
  }
  if( fp == NULL) {
    printf("Missing trace file argument, this is needed to run this"
           " this program properly\n");
    exit(0);
  }



/**************************************************************************
 * This is where where all the structs get defined.
 *
 * I use a queue to keep track of the LRU. There are two arrrays headeres 
 * and tails. Head is at the front of the line and tail is at the end
 * the linked list is double linked.
 *
 * *********************************************************************/

  
  struct line {
    unsigned valid;
    unsigned tag;
    struct line* after;
    struct line* before;
    
  };

  typedef struct line line;
  typedef struct line* set;
  typedef set* cache;


  cache headers = malloc(sizeof(cache) * sbig);

  cache tails = malloc(sizeof(cache) * sbig); 

  cache simcache = malloc(sizeof(cache) * sbig);

  for( i = 0; i < sbig; i++)  {

     simcache[i] = malloc(sizeof(line) * e);
     headers[i] = malloc(sizeof(line*));
     tails[i] = malloc(sizeof(line*));
     for( j = 0; j < e; j++) {
        

        (simcache[i][j]).valid = 0;
        (simcache[i][j]).tag = 0;

        if( j == 0 ) {
          (simcache[i][j]).after = NULL;
          (simcache[i][j]).before = NULL;
          tails[i] = &(simcache[i][j]);
        }
        else if ( j == (e-1) ) {
          (simcache[i][j]).after = &simcache[i][j-1];
          (simcache[i][j]).before = NULL;
          (simcache[i][j-1]).before = &simcache[i][j];
          headers[i] = &(simcache[i][j]);

        }
        else {
          (simcache[i][j]).after = &simcache[i][j-1];
          (simcache[i][j-1]).before = &simcache[i][j];
        }

     }
     
     headers[i] = &(simcache[i][e-1]);

     tails[i] = &(simcache[i][0]);

  }
  
/**************************************************************************
 *
 *This is where we go and parse through the trace file
 * I use a queue to keep a track of the LRU. 
 *
 * *************************************************************************/
 

  char identifier;
  unsigned address;
  int size;

  unsigned currentTag;
  unsigned currentSetIndex;
  int currentIndex;

  int hitCount = 0;
  int missCount = 0;
  int evictionCount = 0;

  int hit;
  int evicted;


  set currentSet;


  while(fscanf(fp," %c %x,%d", &identifier, &address, &size) > 0) {

    currentSetIndex = (address >> b) & ~(~0<<s);
    currentTag = (address >> (b + s)) & ~(~0<<(64-b-s));

    hit = 0;
    evicted = 0;


    currentSet = simcache[currentSetIndex];

    if( identifier == 'L' || identifier == 'S' || identifier == 'M') {

      if (verbose == 1) {
        printf("%c %x,%d",identifier,address,size);
      }
     
      currentSet = simcache[currentSetIndex];
      for ( i = 0; i < e; i++ ) {


        if( currentSet[i].valid == 1 ) {

          evicted++;
          if( (currentSet[i]).tag == currentTag ) {

            currentIndex = i;
            hit = 1;
            break;

          }
        }
      }
/**/
      if( hit == 0 ) {
        missCount++;
       
        //change the values of the line that we are evicting
        headers[currentSetIndex]->valid = 1;
        headers[currentSetIndex]->tag = currentTag;


        if( e > 1) {
 

          //put the newly created line at the end of queue
          tails[currentSetIndex]->after = headers[currentSetIndex];
          headers[currentSetIndex]->before = tails[currentSetIndex];

          //change the pointers of queues to appropriate nodes
          headers[currentSetIndex] = headers[currentSetIndex]->after;

          tails[currentSetIndex] = headers[currentSetIndex]->before;

          //make the ends of queue pointing to NULL outwards
          headers[currentSetIndex]->before = NULL;

          tails[currentSetIndex]->after = NULL;


        }


        if( evicted == (e) ) {
          evictionCount++;
          if( verbose == 1 ) {
            printf(" miss eviction");
          }
        }
        else {
          if( verbose == 1) {
            printf(" miss");
          }
        }
        
      }
    
/**/
      if (hit == 1 || identifier == 'M') {

        if( e > 1 && hit == 1 ) {
          
          //if the node that we are moving is at the head
          if( simcache[currentSetIndex][currentIndex].before == NULL ) {

            //put the head at the end
            tails[currentSetIndex]->after = headers[currentSetIndex];
            headers[currentSetIndex]->before = tails[currentSetIndex];

            //change the pointers of queues to appropriate nodes
            headers[currentSetIndex] = headers[currentSetIndex]->after;
            tails[currentSetIndex] = headers[currentSetIndex]->before;

            //make the ends of queue pointing to NULL outwards
            headers[currentSetIndex]->before = NULL;
            tails[currentSetIndex]->after = NULL;

          }
          // if the node that we are removing is in the middle
          else if( simcache[currentSetIndex][currentIndex].after != NULL ) {
      
            //removing a node in the queue and relinkin the queue 
            (simcache[currentSetIndex][currentIndex].before)->after = 
                              (simcache[currentSetIndex][currentIndex].after);

            (simcache[currentSetIndex][currentIndex].after)->before =
                              (simcache[currentSetIndex][currentIndex].before);

            //putting our removed node at the tail of the queue
            (simcache[currentSetIndex][currentIndex]).before = 
                                  tails[currentSetIndex];
            tails[currentSetIndex]->after = 
                                  &simcache[currentSetIndex][currentIndex];

            (simcache[currentSetIndex][currentIndex]).after = NULL;

            tails[currentSetIndex] = &(simcache[currentSetIndex][currentIndex]);
          }
        }
        
        hitCount++;

        if( hit == 1 && identifier == 'M') {
          hitCount++;
          if (verbose == 1) {
            printf(" hit");
          }
        }

        if (verbose == 1) {       
          printf(" hit");
        }

      }
    if(verbose == 1) {
      printf("\n");
    }
/**/
    }


  }

  fclose(fp);




/*************************************************************************
 *
 *
 * Freeing up memory
 * *********************************************************************/

  for( i = 0; i < sbig; i++)  {
     free(simcache[i]); 
  }
  

  free(simcache);
  free(headers);
  free(tails);

  printSummary(hitCount,missCount,evictionCount);

  return 0;
   
}
