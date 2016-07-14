#include <stdio.h>
#include <math.h>
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
    float f;

    for(i = 0; i < 1000*1000*20; i++)
    {
      f = sinf(3.14f);
    }

  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

