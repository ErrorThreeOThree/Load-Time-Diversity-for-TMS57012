#include "rand.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct mis {
	int id;
	int size;
};

uint32_t reduce(uint32_t x, uint32_t N) {
  return ((uint64_t) x * (uint64_t) N) >> 32 ;
}

int main(int argc, char**argv) {
	if (argc < 3) exit(1);
	int fac = atoi(argv[2]);
	int num_mis = 11*fac;
	int runs = atoi(argv[1]);
	int i, j, run;
	int current_start_address = 0;
	int total_size = 0;

	rand_set_seed(0);

	struct mis *miss = malloc(sizeof(struct mis) * num_mis);
	int *start_address = malloc(sizeof(struct mis) * runs);

	for (i = 0; i < num_mis; i+=11) {
		miss[i+0].size = 6;
			miss[i+1].size = 5;
				miss[i+2].size = 5;
					miss[i+3].size = 8;
						miss[i+4].size = 16;
							miss[i+5].size = 1;
								miss[i+6].size = 4;
									miss[i+7].size = 4;
										miss[i+8].size = 4;
											miss[i+9].size = 1;
												miss[i+10].size = 1;
											}

	for (i = 0; i < num_mis; i++) {
		miss[i].id = i;
		start_address[i] = current_start_address;
		current_start_address += miss[i].size;
	}
	total_size = current_start_address;
	printf("total: %d\n", total_size);
	int *arr = malloc(sizeof(int) * total_size);
	for (i = 0; i < total_size; i++) {
		arr[i] = 0;
	}

	for (run = 0; run < runs; run++ ) {
		 for (i = num_mis-1; i > 0; i--) {
			 j = reduce(rand_custom(), i+1);
			 //swap id_to_position[i] and id_to_position[j]
			 struct mis tmp = miss[i];
			 miss[i] = miss[j];
			 miss[j] = tmp;
			 //printf("swapping %d id: %d and %d id:%d\n", i, miss[i].id, j, miss[j].id);
		}

		current_start_address = 0;
		// find id 0
		for (i = 0; miss[i].id != 0; i ++) {
			current_start_address += miss[i].size;
		}
		start_address[run] = current_start_address;
		arr[start_address[run]] += 1;
	}

	for (i = 0; i < total_size; i++ ) {
		printf("%d;", arr[i]);
	}
	printf("\n");

}
