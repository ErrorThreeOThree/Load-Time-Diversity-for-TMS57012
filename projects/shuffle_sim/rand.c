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
uint32_t rand_custom(void) {
    seed = (uint64_t)(seed_g * 0x5DEECE66D + 0xBL)% ((uint64_t)1<<48);
	/* return bits 16 to 47 */
    return (seed_g>>16) & 0xFFFFFFFF;
}
