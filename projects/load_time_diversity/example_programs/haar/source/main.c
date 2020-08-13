#include "haar.h"
#include "stdint.h"

typedef unsigned long long uint64_t;

uint8_t input[ROWS * COLS] = {1};
uint8_t output[ROWS * COLS] = {1};

uint32_t randustom(uint64_t *seed) {
    (*seed) = (uint64_t)((*seed) * 0x5DEECE66D + 0xBL)% ((uint64_t)1<<48);
	/* return bits 16 to 47 */
    return ((*seed) >>16) & 0xFFFFFFFF;
}

int main()
{
	uint64_t seed = 0;

	for (uint32_t i = 0; i < COLS * ROWS; i++)
		input[0] = randustom(&seed);

	haar(&output[0], &input[0]);

	while (1);
}
