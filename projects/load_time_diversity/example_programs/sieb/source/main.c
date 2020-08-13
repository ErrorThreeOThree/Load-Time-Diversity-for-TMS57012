#include "bool.h"
#include "sieb.h"

#define SQRT_N 40
#define N (SQRT_N*SQRT_N)

#define ERROR 0xE1212012
#define FIN 0x12167

uint32_t array_eq(const bool *a1, const bool *a2, uint32_t size);

void sys_exit(uint32_t code, uint32_t error_code, const bool* val_a, const bool* val_b);

int main() {
	bool primes[N+1];

	uint32_t code;

	sieb(&primes[0], N, SQRT_N);
	// code = array_eq(&primes[0], &solution[0], (N+1));
	// if ((N+1) == code) {
	// 	// puts("done");
	// 	sys_exit(code, FIN, &primes[0], &solution[0]);
	// } else {
	// 	// printf("wong %d: %d, %d\n", code, primes[code], solution[code]);
	// 	sys_exit(code, ERROR, &primes[0], &solution[0]);
	// }
	while(1);
}

uint32_t array_eq(const bool *a1, const bool *a2, uint32_t size) {
	int i;
	for (i = 0; i < size; i++) {
		// if (a1[i]) {
		// 	printf("%d\n", i);
		// }
		if (a1[i] != a2[i])
			return i;
	}
	return size;
}

void sys_exit(uint32_t code, uint32_t error_code, const bool* val_a, const bool* val_b) {
	while (1);
}
