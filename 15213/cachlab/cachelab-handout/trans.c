/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"
#include "contracts.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. The REQUIRES and ENSURES from 15-122 are included
 *     for your convenience. They can be removed if you like.
 */

/*
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    REQUIRES(M > 0);
    REQUIRES(N > 0);

    int i;
    int j;
   
    int x = 8;
    int y = 8;

    int m;
    int n;


    int tmp;
 
    for( i = (N/x)-1; i >= 0; i--){
      for( j = 0; j*y < M;j++){
      
            for( n = 0; n < x; n++){
               for( m = 0; m < y; m++){

                     tmp = A[i*x+m][j*y+n];
                     B[j*y+n][i*x+m] = tmp;

               }
            }
      }
    }




    ENSURES(is_transpose(M, N, A, B));
}
*/
char trans_desc2[] = "Messing around";
void trans_testing(int M, int N, int A[N][M], int B[M][N])
{
    REQUIRES(M > 0);
    REQUIRES(N > 0);

    int i;
    int j;
   
    int x = 16;
    int y = 16;

    int m;
    int n;

    int tmp;
 
    for( i = 0; i*x < N;i++){
      for( j = 0; j*y < M;j++){
         
         for( n = 0; n < x; x++){
            for( m = 0; m < y; m++){
               tmp = A[i*x+m][j*y+n];
               B[j*y+n][i*x+m] = tmp;
            }
         }
      }
    }




    ENSURES(is_transpose(M, N, A, B));
}

char trans_desc3[] = "Transpose test";
void trans_test2(int M, int N, int A[N][M], int B[M][N])
{
    REQUIRES(M > 0);
    REQUIRES(N > 0);

    int i;
    int j;
   
    int x = 8;
    int y = 8;

    int x2 = 4;
    int y2 = 4;

    int m;
    int n;

    int m2;
    int n2;

    int tmp;
 
    for( i = 0; i*x < N;i++){
      for( j = 0; j*y < M;j++){
         if( i != j ) { 
           for( m = 0; m < x; m++){
              for( n = 0; n < y; n++){
                 tmp = A[i*x+m][j*y+n];
                 B[j*y+n][i*x+m] = tmp;
              }
           }
         }
   /*      else {
           for( m = 0; m < x; m = m+x2){
              for( n = 0; n < y; n = n+y2){

                 tmp = A[i(i*x)+m][j*y+n];
                 B[j*y+n][i*x+m] = tmp;
              }
           }
 
         } */
      }
    }


    for( i = 0; i*x < M;i++) {


       for ( m = 0; m < x;m=m+x2){
          for( n = 0; n < y; n=n+y2) {

             for( m2 = 0; m2 < x2; m2++) {
                for ( n2 = 0; n2 < y2; n2++) {
                    tmp = A[(i*x)+m+m2][(i*x)+n+n2];
                    B[(i*x)+n+n2][(i*x)+m+m2] = tmp;
                 }
             }
          }
        }
    }




    ENSURES(is_transpose(M, N, A, B));
}


char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    REQUIRES(M > 0);
    REQUIRES(N > 0);

    int i;
    int j;
   
    int x = 8;
    int y = 8;


    int x2 = 4;
    int y2 = 4;
    
 
    int m;
    int n;

    int m2;
    int n2;

    int tmp;

    if( M == 67 && N == 61 ) {
      for( i = 0; i < M; i++) {
         for ( j = 0; j < N; j++) {
            tmp = A[j][i];
            B[i][j] = tmp;
         }
      }
    }
   else {
      for( i = 0; i < N;i+=x){
        for( j = 0; j < M;j+=y){
  
           
             for( m = 0; m < y; m+=y2){

                   n = 0;
                   for(m2 = 0; m2 < y2 ; m2++) {
                      for(n2 = 0; n2 < y2; n2++) {

                         tmp = A[i+n+n2][j+m+m2];
                         B[j+m+m2][i+n+n2] = tmp;
  
                      }
                   }
             }
             for( m = y2; m >= 0; m-=y2 ) {

                   n = x2;
                   for(m2 = 0; m2 < y2; m2++) {
                      for(n2 = 0;n2 < y2; n2++) {

                         tmp = A[i+n+n2][j+m+m2];
                         B[j+m+m2][i+n+n2] = tmp;

                      }
                   }

             }

        } 
     }
     if( N == 61 && M == 67) {

        for( i = 0; i <= 60; i++) {
           tmp = A[60][i];
           B[i][60] = tmp;
      
        }

        for( i = 0; i <61; i++) {
           for( j = 61; j < 67;j++) {

             tmp = A[i][j];
             B[j][i] = tmp;

           }
        }


     }
  }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    REQUIRES(M > 0);
    REQUIRES(N > 0);

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

    ENSURES(is_transpose(M, N, A, B));
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
/*    registerTransFunction(trans, trans_desc); */

  /*  registerTransFunction(trans_test3,trans_desc4);*/
}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

