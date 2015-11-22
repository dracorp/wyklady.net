#include <stdio.h>
#include "rtdsc.c"
#include "speed.h"

int sth[20*1024*1024];

int
main(void)
{
  uint64_t rnow;
  
  tcount();
  rnow = rdtsc();

  // code
  {
    int sum = 0, i;
    for(i = 0; i < sizeof(sth) / sizeof(sth[0]); i += 4)
    {
      sum += sth[i];
      sum += sth[i+1];
      sum += sth[i+2];
      sum += sth[i+3];
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

