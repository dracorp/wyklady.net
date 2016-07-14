#include <stdio.h>
#include "include/rtdsc.c"
#include "include/speed.h"

  int
main(void)
{
  uint64_t rnow;

  tcount();
  rnow = rdtsc();

  // code
  {
    int i;
    int a = 0, b = 0;

    for(i = 0; i < 1000*1000*100; i++)
    {
      a++;
      b++;
    }

  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

