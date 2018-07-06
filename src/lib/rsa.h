#include <gmp.h>

#ifndef RSA_H
#define RSA_H

/**
 * @brief Generates public and private keys for the RSA cryptography.
 * 
 * @param n [output] The n used for the public and private keys.
 * @param e [output] The e used for the public key.
 * @param d [output] The d used for the private key.
 * @param randstate [input] Random seed.
 */
void key_gen(mpz_t n,
             mpz_t e,
             mpz_t d,
             gmp_randstate_t rnd);

/**
 * @brief Encodes a string in 256 base.
 * 
 * @param r [output] The number for the encoded string.
 * @param str [input] The string to be encoded.
 */
void encode(mpz_t r, const char *str);

/**
 * @brief Decodes a number into the original string.
 * 
 * @param n [input] The number to be decoded.
 * @return char* The decoded string.
 */
char *decode(const mpz_t n);

/**
 * @brief Ecrypts a encoded message.
 * 
 * @param C [output] The encrypted message.
 * @param M [input] The encoded message.
 * @param n [input] The n of the public key.
 * @param e [input] The e of the public key.
 */
void encrypt(mpz_t C,
             const mpz_t M,
             const mpz_t n,
             const mpz_t e);

/**
 * @brief Decrypts an encrypted message.
 * 
 * @param M [output] The decrypted message.
 * @param C [input] The encrypted message.
 * @param n [input] The n of the private key.
 * @param d [input] The e of the private key.
 */
void decrypt(mpz_t M,
             const mpz_t C,
             const mpz_t n,
             const mpz_t d);

#endif
