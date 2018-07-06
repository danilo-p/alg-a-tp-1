#include <gmp.h>

#ifndef RSA_H
#define RSA_H

void key_gen(mpz_t n,
             mpz_t e,
             mpz_t d,
             gmp_randstate_t rnd);

void encode(mpz_t r, const char *str);

char *decode(const mpz_t n);

void encrypt(mpz_t C,
             const mpz_t M,
             const mpz_t n,
             const mpz_t e);

void decrypt(mpz_t M,
             const mpz_t C,
             const mpz_t n,
             const mpz_t d);

#endif
