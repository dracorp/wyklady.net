#include <stdio.h>
#include "rtdsc.c"
#include "speed.h"

int dodaj(int a, int b)
{
  return a + b;
}

int func(int *sth)
{
  int i, j = 0, local = *sth;
  for(i = 0; i < 1000*1000*100; i++)
    j += dodaj(local, 5);

  return j;
}

int
main(void)
{
  uint64_t rnow;

  tcount();
  rnow = rdtsc();

  // code
  {
    int a = 12, b;
    b = func(&a);
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);

  return 0;
}

