#include "sieb.h"

// n+1 is size of bool_primes array
bool * sieb(bool *bool_primes, uint32_t n, uint32_t sqrt_n) {
	int i, j;

	for (i = 0; i <= n; i++) {
		bool_primes[i] = TRUE;
	}

	for (i = 2; i <= sqrt_n; i++) {
		if (bool_primes[i] == TRUE) {
			for (j = i*i; j <= n; j+=(i)) {
				bool_primes[j] = FALSE;
			}
		}
	}
	return bool_primes;
}
