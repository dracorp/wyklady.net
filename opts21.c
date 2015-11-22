#include <stdio.h>
#include "rtdsc.c"
#include "speed.h"

int dane[2000][1000];


int
main(void)
{
  uint64_t rnow;

  tcount();
  rnow = rdtsc();

  // code
  {
    int i, j, k, sum;

    for(i = 0; i < 100; i++)
    {
      sum = 0;

      for(j = 0; j < 1000; j++)
        for(k = 0; k < 2000; k++)
          sum += dane[k][j];     
    }

  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

