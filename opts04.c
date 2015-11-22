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

      switch(j % 26)
      {
        case 0: g += '0'; break;
        case 1: g += '1'; break;
        case 2: g += '2'; break;
        case 3: g += '3'; break;
        case 4: g += '4'; break;
        case 5: g += '5'; break;
        case 6: g += '6'; break;
        case 7: g += '7'; break;
        case 8: g += '8'; break;
        case 9: g += '9'; break;
        case 10: g += 'A'; break;
        case 11: g += 'B'; break;
        case 12: g += 'C'; break;
        case 13: g += 'D'; break;
        case 14: g += 'E'; break;
        case 15: g += 'F'; break;
        case 16: g += 'G'; break;
        case 17: g += 'H'; break;
        case 18: g += 'I'; break;
        case 19: g += 'J'; break;
        case 20: g += 'K'; break;
        case 21: g += 'L'; break;
        case 22: g += 'M'; break;
        case 23: g += 'N'; break;
        case 24: g += 'O'; break;
        case 25: g += 'P'; break;
      }
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

