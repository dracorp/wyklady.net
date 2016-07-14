#include <stdio.h>
#include "include/rtdsc.c"
#include "include/speed.h"

int sth[20*1024*1024]; // 80mb!!!

int
main(void)
{
  uint64_t rnow;
 
  tcount();
  rnow = rdtsc();

  // code
  {
    int sum = 0, i;
    for(i = 0; i < sizeof(sth) / sizeof(sth[0]); i++)
    {
      sum += sth[i];
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

