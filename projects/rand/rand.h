#ifndef RAND_H
#define RAND_H

#include <stdint.h>
// set the seed
void rand_set_seed(uint64_t seed);

// return the value of the seed
uint64_t rand_get_seed(void);

// returns a pseudo-random number. Changes the seed.
uint32_t rand_custom(void);

#endif
