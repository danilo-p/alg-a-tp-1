#include <gmp.h>

#ifndef PRIMALITY_H
#define PRIMALITY_H

int maybe_prime(const mpz_t a,
                const mpz_t n,
                const mpz_t n1,
                unsigned int t,
                const mpz_t q);

void random_mod_n(mpz_t r, const mpz_t n, gmp_randstate_t rand_state);

int probably_prime(const mpz_t n,
                   unsigned int iter,
                   gmp_randstate_t rand_state);

#endif
