#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "rsa.h"
#include "primality.h"
#include "arithmetics.h"

void key_gen(mpz_t n,
             mpz_t e,
             mpz_t d,
             gmp_randstate_t randstate)
{
    mpz_t p;
    mpz_init(p);
    random_prime(p, 2048, randstate);

    mpz_t q;
    mpz_init(q);
    random_prime(q, 2048, randstate);

    mpz_mul(n, p, q);

    mpz_t p1;
    mpz_init(p1);
    mpz_sub_ui(p1, p, 1);

    mpz_t q1;
    mpz_init(q1);
    mpz_sub_ui(q1, q, 1);

    mpz_t fi_n;
    mpz_init(fi_n);
    mpz_mul(fi_n, p1, q1);

    mpz_set_ui(e, 65537);
    modular_inverse(d, e, fi_n);

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(p1);
    mpz_clear(q1);
    mpz_clear(fi_n);
}

void encode(mpz_t r, const char *str)
{
    mpz_t b;
    mpz_init(b);
    mpz_t aux;
    mpz_init(aux);

    char c;
    int c_ascii;
    int i = 0;
    mpz_set_ui(b, 1);
    mpz_set_ui(r, 0);
    while (str[i] != '\0')
    {
        c = str[i];
        c_ascii = (int)c;
        mpz_mul_ui(aux, b, c_ascii);
        mpz_add(r, r, aux);
        mpz_mul_ui(b, b, 256);
        i += 1;
    }

    mpz_clear(b);
    mpz_clear(aux);
}

char *decode(const mpz_t n)
{
    char *str = (char *)malloc(sizeof(500 * sizeof(char)));

    mpz_t x;
    mpz_init_set(x, n);
    mpz_t c_ascii;
    mpz_init(c_ascii);

    int i = -1;
    char c;
    do
    {
        i += 1;
        mpz_mod_ui(c_ascii, x, 256);
        mpz_sub(x, x, c_ascii);
        mpz_div_ui(x, x, 256);
        c = (char)mpz_get_ui(c_ascii);
        str[i] = c;
    } while (str[i] != '\0');

    mpz_clear(x);
    mpz_clear(c_ascii);

    return str;
}

void encrypt(mpz_t C,
             const mpz_t M,
             const mpz_t n,
             const mpz_t e)
{
    binary_exp(C, M, e, n);
}

void decrypt(mpz_t M,
             const mpz_t C,
             const mpz_t n,
             const mpz_t d)
{
    binary_exp(M, C, d, n);
}