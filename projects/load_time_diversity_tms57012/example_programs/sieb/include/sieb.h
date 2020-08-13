#ifndef SIEB_H
#define SIEB_H

#include "bool.h"

typedef unsigned long int uint32_t;

// sqrt_n is size of bool_primes array
bool * sieb(bool *bool_primes, uint32_t n, uint32_t sqrt_n);

#endif // SIEB_H
