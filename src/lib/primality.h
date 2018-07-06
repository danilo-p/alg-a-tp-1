#include <gmp.h>

#ifndef PRIMALITY_H
#define PRIMALITY_H

int maybe_prime(const mpz_t a,
                const mpz_t n,
                const mpz_t n1,
                unsigned int t,
                const mpz_t q);

int probably_prime(const mpz_t n,
                   unsigned int iter,
                   gmp_randstate_t randstate);

void random_number(mpz_t r,
                   const mpz_t n,
                   gmp_randstate_t randstate);

void random_prime(mpz_t r,
                  unsigned int b,
                  gmp_randstate_t randstate);

#endif
