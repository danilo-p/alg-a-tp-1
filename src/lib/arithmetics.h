#include <gmp.h>

#ifndef ARITHMETICS_H
#define ARITHMETICS_H

/**
 * @brief Given two numbers a and b, it computes x, y, and g that gcd(a, b) = g
 * and a*x + b*y = g.
 * 
 * @param g [output] The gcd of a and b.
 * @param x [output] x that a*x + b*y = g.
 * @param y [output] y that a*x + b*y = g.
 * @param a [input] The a number.
 * @param b [input] The b number.
 */
void gcd_extended(mpz_t g, mpz_t x, mpz_t y,
                  const mpz_t a, const mpz_t b);

/**
 * @brief Determines if a has inverse modulo n. In case of positive, it computes
 * the a inverse modulo n.
 * 
 * @param r [output] The a inverse modulo n.
 * @param a [input] The number.
 * @param n [input] The modulo.
 * @return int 1 if a has inverse modulo n. 0 instead.
 */
int modular_inverse(mpz_t r,
                    const mpz_t a,
                    const mpz_t n);

/**
 * @brief Calculates the exponetiation of b and the given exponent modulo n. It
 * uses the binary exponentiation.
 * 
 * @param r [output] The result of the exponentiation.
 * @param b [input] The base of the exponentiation.
 * @param e [input] The exponent of the exponentiation.
 * @param n [input] The modulo of the exponentiation.
 */
void binary_exp(mpz_t r,
                const mpz_t b,
                const mpz_t e,
                const mpz_t n);

#endif
