#include <stdio.h>
#include "include/rtdsc.c"
#include "include/speed.h"

int sth[20*1024*1024];

int
main(void)
{
  uint64_t rnow;
  
  tcount();
  rnow = rdtsc();

  // code
  {
    int sum = 0, i, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(i = 0; i < sizeof(sth) / sizeof(sth[0]); i += 4)
    {
      sum1 += sth[i];
      sum2 += sth[i+1];
      sum3 += sth[i+2];
      sum4 += sth[i+3];
    }
    sum = (sum1 + sum2) + (sum3 + sum4);
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

