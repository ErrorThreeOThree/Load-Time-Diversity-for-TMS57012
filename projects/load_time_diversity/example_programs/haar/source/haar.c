#include "haar.h"
#include "string_custom.h"

// This code is a modified version of https://isis.tu-berlin.de/course/view.php?id=16384

uint8_t avg(uint8_t a, uint8_t b)
{
	return (uint8_t) (((uint32_t) a + (uint32_t) b + 1) / 2);
}

void haar_x(uint8_t *output, const uint8_t *input) {
	for (uint32_t y = 0; y < ROWS; y++)
	{
		uint8_t tmp[COLS];
		memcpy_custom(tmp, &input[y * COLS], COLS);

		for (uint32_t lim = COLS; lim > 1; lim /= 2) {
			for (uint32_t x = 0; x < lim; x += 2) {
				uint8_t a = tmp[x];
				uint8_t b = tmp[x+1];
				uint8_t s = avg(a, b);
				uint8_t d = avg(a, -b);

				tmp[x/2] = s;
				output[y * COLS + (lim+x)/2] = d;
			}
		}

		output[y * COLS] = tmp[0];
	}
}

void haar_y(uint8_t *output, const uint8_t *input) {
	for (uint32_t x = 0; x < COLS; x++)
	{
		uint8_t tmp_inputol[ROWS];
		for (uint32_t y = 0; y < ROWS; y++)
		{
			tmp_inputol[y] = input[y * COLS + x];
		}

		for (uint32_t lim = COLS; lim > 1; lim /= 2)
		{
			for (uint32_t y = 0; y < lim; y += 2)
			{
				uint8_t a = tmp_inputol[y];
				uint8_t b = tmp_inputol[y+1];
				uint8_t s = avg(a, b);
				uint8_t d = avg(a, -b);

				tmp_inputol[y/2] = s;
				output[(lim+y)/2 * COLS + x] = d;

				//printf("COL <%lu>: [x] = [%lu] => %02x, [x] = [%lu] => %02x\n", x, (lim+y)/2 * COLS + x, d, y/2, s);
			}
		}

		output[x] = tmp_inputol[0];
		//printf("\n");
	}

}

void haar(uint8_t *output, const uint8_t *input)
{
	uint8_t tmp[ROWS*COLS];
	haar_x(tmp, input);
	haar_y(output, tmp);
}
