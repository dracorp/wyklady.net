#include <stdio.h>
#include "rtdsc.c"
#include "speed.h"

int
main(void)
{
  uint64_t rnow;

  tcount();
  rnow = rdtsc();

  // code
  {
    int i, j = 1234, g = 0;
    for(i = 0; i < 1000*1000*100; i++)
    {
      j += 9111;
      g += "0123456789ABCDEFGHIJKLMNOP"[j % 26];
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

