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
    int i, j = 1234, g = 0, h;
    for(i = 0; i < 1000*1000*100; i++)
    {
      j += 9111;
      h = j % 26;

      if(h < 13)
      {
        if(h < 6)
        {
          if(h == 0) g += '0'; 
          else if(h == 1) g += '1'; 
          else if(h == 2) g += '2'; 
          else if(h == 3) g += '3'; 
          else if(h == 4) g += '4'; 
          else g += '5'; 
        }
        else
        {
          if(h == 6) g += '6'; 
          else if(h == 7) g += '7'; 
          else if(h == 8) g += '8'; 
          else if(h == 9) g += '9'; 
          else if(h == 10) g += 'A'; 
          else if(h == 11) g += 'B'; 
          else g += 'C'; 
        }
      }
      else
      {
        if(h < 19)
        {
          if(h == 13) g += 'D'; 
          else if(h == 14) g += 'E'; 
          else if(h == 15) g += 'F'; 
          else if(h == 16) g += 'G'; 
          else if(h == 17) g += 'H'; 
          else g += 'I'; 
        }
        else
        {
          if(h == 19) g += 'J'; 
          else if(h == 20) g += 'K'; 
          else if(h == 21) g += 'L'; 
          else if(h == 22) g += 'M'; 
          else if(h == 23) g += 'N'; 
          else if(h == 24) g += 'O'; 
          else g += 'P'; 
        }
      }
    }
  }
  // end of code

  rnow = rdtsc() - rnow;
  tcount();
  fprintf(stderr, "RDTSC DIFF: %u\n", (uint32_t) rnow);




  return 0;
}

