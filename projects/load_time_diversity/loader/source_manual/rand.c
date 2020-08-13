/** @file
*   @brief Pseudo-random number generator source file
*   @date 19-06-07
*   @version 0.1
*
*   Linear congruential generator pseudo-random number generator source file.
*   Uses the values POSIX[21] [jm]rand48. Source of values: https://en.wikipedia.org/wiki/Linear_congruential_generator
*/

#include "rand.h"

/**
 * Stores the seed
 */
uint64_t seed_g;

/**
 * @brief Sets a new seed value
 * @param[in] new_seed New seed value
 *
 * Sets a new seed value by setting seed_g to @p new_seed
 */
void rand_set_seed(uint64_t new_seed) {
    seed_g = new_seed;
}

/**
 * Gets the current seed value
 * @return current seed value
 *
 * Gets the current seed value by returning seed_g
 */
uint64_t rand_get_seed(void) {
    return seed_g;
}

/**
 * Returns a random number
 * @return random number
 *
 * Returns a pseudo-random number and changes the seed seed_g
 */
uint32_t rand_custom(void) {
    seed_g = (uint64_t)(seed_g * 0x5DEECE66D + 0xBL)% ((uint64_t)1<<48);
	/* return bits 16 to 47 */
    return (seed_g>>16) & 0xFFFFFFFF;
}
