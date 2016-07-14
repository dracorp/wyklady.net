#include <stdio.h>
#include "include/rtdsc.c"
#include "include/speed.h"

struct ala
{
  int a, b, c, d;
  float e, f;
};

int func(struct ala sth)
{
  return sth.a + sth.b + sth.c + sth.d;
}

int
main(void)
{
  uint64_t rnow;

  tcount();
  rnow = rdtsc();

  // code
  {
    struct ala x = { 1,2,3,4,5.0f, 6.0f };
    int i, a = 0;

    for(i = 0; i < 1000*1000*100; i++)
    {
      a = func(x); 
    }

  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

