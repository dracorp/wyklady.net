/* 
 * VLI Multiplication Compo
 *   (Speed Test Module)
 *
 * Author: gynvael.coldwind//vx
 * Desc  : just include this module at the begining of your source
 */
 
#ifndef TM__H
  #define TM__H
  
  #include<time.h>
  #include<stdio.h>
  
  void
  tcount( void )
  {
    static long   start, finish;
    static double dur;
    
    if( !finish )
    {
      /* the first call
       */
      start = clock( );
      finish = 1;
      return;
    }
    
    /* the second call
     */
    finish = clock( );
    start = finish - start;
    dur = (double)( start ) / CLOCKS_PER_SEC;
    printf( "TICKS: %.9u\tTIME: %.5lf sec\n",
             start, dur );
    finish = 0;
  }
#endif
 
 
