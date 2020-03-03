#include "deadbeef_rand.h"
#include <time.h>
#include <math.h>

static uint32_t deadbeef_seed;
static uint32_t deadbeef_beef = 0xdeadbeef;

uint32_t deadbeef_rand(void)
{
	deadbeef_seed = (deadbeef_seed << 7) ^ ((deadbeef_seed >> 25) + deadbeef_beef);
	deadbeef_beef = (deadbeef_beef << 7) ^ ((deadbeef_beef >> 25) + 0xdeadbeef);
	return deadbeef_seed;
}

void deadbeef_srand(uint32_t x)
{
	deadbeef_seed = x;
	deadbeef_beef = 0xdeadbeef;
}

/* Taken directly from the documentation:
 * http://inglorion.net/software/cstuff/deadbeef_rand/ */
uint32_t deadbeef_generate_seed(void)
{
	  uint32_t t = (uint32_t)time(NULL);
	  uint32_t c = (uint32_t)clock();
	  return (t << 24) ^ (c << 11) ^ t ^ (size_t) &c;
}

float rand_bm()
{
   float u = 0, v = 0;

   while(u == 0) u = deadbeef_rand() / pow(2, 32);
   while(v == 0) v = deadbeef_rand() / pow(2, 32);

   float num = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
   num = num / 10.0 + 0.5; // Translate to 0 -> 1

   if (num > 1 || num < 0) return rand_bm(); // resample between 0 and 1

   return num;
}
