#include <gmp.h>

#ifndef ARITHMETICS_H
#define ARITHMETICS_H

void gcd_extended(mpz_t g, mpz_t x, mpz_t y,
                  const mpz_t a, const mpz_t b);

int modular_inverse(mpz_t r,
                    const mpz_t a,
                    const mpz_t n);

void binary_exp(mpz_t r,
                const mpz_t b,
                const mpz_t e,
                const mpz_t n);

#endif
