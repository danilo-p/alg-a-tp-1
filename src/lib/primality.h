#include <gmp.h>

#ifndef PRIMALITY_H
#define PRIMALITY_H

int maybe_prime(const mpz_t a,
                 const mpz_t n,
                 const mpz_t n1,
                 unsigned int t,
                 const mpz_t q);

#endif
