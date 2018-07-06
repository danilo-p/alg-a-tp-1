#include <gmp.h>

#ifndef PRIMALITY_H
#define PRIMALITY_H

/**
 * @brief Test if the number is prime using a as basis for the miller primality
 * test.
 * 
 * @param a [input] The base for the test.
 * @param n [input] The number to be tested.
 * @param n1 [input] Convenience input that holds n - 1;
 * @param t [input] Convenience input t for the expression n - 1 = (2^t) * q;
 * @param q [input] Convenience input q for the expression n - 1 = (2^t) * q;
 * @return int 0 if certain composite. 1 if maybe prime.
 */
int maybe_prime(const mpz_t a,
                const mpz_t n,
                const mpz_t n1,
                unsigned int t,
                const mpz_t q);

/**
 * @brief Test if the number is prime using a as basis for the miller-rabin
 * primality test.
 * 
 * @param n [input] The number to be tested.
 * @param iter [input] The number of iterations for the test.
 * @param randstate [input] Random seed.
 * @return int 0 if certain composite. 1 if probably prime.
 */
int probably_prime(const mpz_t n,
                   unsigned int iter,
                   gmp_randstate_t randstate);

/**
 * @brief Generates a random number lower than the given limit.
 * 
 * @param r [output] The generated random number.
 * @param n [input] The limit for the random number.
 * @param randstate [input] Random seed.
 */
void random_number(mpz_t r,
                   const mpz_t n,
                   gmp_randstate_t randstate);

/**
 * @brief Generates a random prime with b bits.
 * 
 * @param r [output] The generated random prime.
 * @param b [input] The bits number.
 * @param randstate [input] Random seed.
 */
void random_prime(mpz_t r,
                  unsigned int b,
                  gmp_randstate_t randstate);

#endif
