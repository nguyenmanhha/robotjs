
#include <stdlib.h>
#include <math.h>

#include "rand.h"
#include "deadbeef_rand.h"



float randBm() {
   return rand_bm();
}

unsigned int randTimeBm(unsigned int min, unsigned int max) {
   float maxFactor = (max - min) / 2;

   return randBm() * maxFactor +  randm() * maxFactor + min;
}

unsigned int randTimeSin(unsigned int min, unsigned int max) {
   float maxFactor = (max - min) / 2;
   float randB = rand_bm();
   float randM = randm();

   return (randB * maxFactor) + abs(sin(randM) * maxFactor) + min;
}
