#include <stdio.h>
#include <stddef.h>
#include "rand.h"

int main() {
	for (int i = 0; i < 10; i++) {
		printf("%d %lu\n", rand(), rand_get_seed());
	}
}
