#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "diversification.h"

int main(int argc, char** argv) {
	// uncomment to mute this program. good for increasing speed ;)
	int result, i;
	int noVerify = 0;
	uint64_t seed = time(NULL);

	for (i = 1; i < argc; i++) {
		if (0 == strcmp(argv[i], "-seed") && (++i > argc)) {
			seed = strtoll(argv[1], NULL, 10);
		} else if (0 == strcmp(argv[i], "-noVerify")) {
			noVerify = 1;
		}
	}

	debug_print("Starting Simulation...\n");
	debug_print("Initializing diversification data... ");
	struct div_data data;
	simulation_init(&data, seed);
	debug_print(" done!\n\n");

	debug_print("\n\nData before shuffling:\n");
	print_div_data(&data);
	print_load_code(&data);
	print_exec_code(&data);

	debug_print("Generating order... ");
	div_shffl_order(&data);
	debug_print(" done!\n\n");

	debug_print("Loading code in new order... ");
	div_load_exec_code(&data);
	debug_print(" done!\n\n");
	debug_print("\n\nData after shuffling:\n");
	print_div_data(&data);
	print_load_code(&data);
	print_exec_code(&data);

	if (!noVerify) {
		debug_print("\n\nVerfivying executable code... ");

		result = div_verify_exec_code(&data);
		if (-1 == result) {
			debug_print(" succesfully verified with seed %lu!\n", div_get_seed());
			return 0;
		} else {
			fprintf(stderr, " verification error: Instruction at %05d and seed %lu!\n", result, div_get_seed());
			return 0;
		}
	}
	return 1;
}
