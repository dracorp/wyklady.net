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
    short a = 11;
    short b, c;

    for(i = 0; i < 1000*1000*100; i++)
    {
      b = a * a + a / 10;
      c = a * b + a;
      a += b + c;
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

