#include <stdint.h>

__inline__ uint64_t rdtsc() {
  uint64_t x;
  __asm__ volatile ("rdtsc\n\t" : "=A" (x));
  return x;
}

