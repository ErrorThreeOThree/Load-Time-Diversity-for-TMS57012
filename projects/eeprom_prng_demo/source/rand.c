#include "rand.h"
uint64_t seed = 0;


// set the seed
void rand_set_seed(uint64_t new_seed) {
    seed = new_seed;
}

// return the value of the seed
uint64_t rand_get_seed(void) {
    return seed;
}

// returns a pseudo-random number. Changes the seed.
uint32_t rand() {
    uint64_t multiplier = 0x5DEECE66D;
    uint64_t increment = 11;
    seed = (seed * multiplier + increment)% (uint64_t)(2UL<<30);
    return (seed>>16) & 0xFFFFFFFF;
}
