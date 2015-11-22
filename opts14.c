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
    int i;
    float a = 11.0f;
    float b, c;

    for(i = 0; i < 1000*1000*100; i++)
    {
      b = a * a + a / 10.0;
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

