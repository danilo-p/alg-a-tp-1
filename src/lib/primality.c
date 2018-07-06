#include <stdio.h>
#include <gmp.h>
#include "arithmetics.h"
#include "primality.h"

int maybe_prime(const mpz_t a,
                const mpz_t n,
                const mpz_t n1,
                unsigned int t,
                const mpz_t q)
{
    mpz_t r;
    mpz_init(r);
    unsigned int i;
    int inconclusive = 0;

    mpz_mod(r, a, n);
    if (mpz_cmp_ui(r, 0) == 0)
    {
        inconclusive = 1;
        goto end;
    }

    binary_exp(r, a, q, n);
    if (mpz_cmp_ui(r, 1) == 0)
    {
        inconclusive = 1;
        goto end;
    }

    i = 1;
    while (i < t)
    {
        mpz_mul(r, r, r);
        mpz_mod(r, r, n);
        if (mpz_cmp(r, n1) == 0)
        {
            inconclusive = 1;
            goto end;
        }

        i += 1;
    }

end:
    mpz_clear(r);

    return inconclusive;
}

int probably_prime(const mpz_t n,
                   unsigned int iter,
                   gmp_randstate_t randstate)
{
    mpz_t base;
    mpz_init(base);

    mpz_t q;
    mpz_init(q);

    mpz_t n1;
    mpz_init(n1);
    mpz_sub_ui(n1, n, 1);

    unsigned int i;
    unsigned int t = 0;
    int inconclusive = 1;

    mpz_set(q, n1);
    while (mpz_cmp_ui(q, 0) != 0 && mpz_even_p(q))
    {
        ;
        mpz_div_ui(q, q, 2);
        t += 1;
    }

    for (i = 0; i < iter; i += 1)
    {
        do
        {
            random_number(base, n, randstate);
        } while (mpz_cmp_ui(base, 2) < 0);

        if (maybe_prime(base, n, n1, t, q) == 0)
        {
            inconclusive = 0;
            goto end;
        }
    }

end:
    mpz_clear(base);
    mpz_clear(q);
    mpz_clear(n1);
    return inconclusive;
}

void random_number(mpz_t r,
                   const mpz_t n,
                   gmp_randstate_t randstate)
{
    mp_bitcnt_t num_bits = mpz_sizeinbase(n, 2);
    do
    {
        mpz_urandomb(r, randstate, num_bits);
    } while (!(mpz_cmp_ui(r, 1) >= 0 && mpz_cmp(r, n) <= 0));
}

void random_prime(mpz_t r,
                  unsigned int b,
                  gmp_randstate_t randstate)
{
    do
    {
        mpz_urandomb(r, randstate, b);
    } while (mpz_cmp_ui(r, 2) < 0 || !probably_prime(r, 10, randstate));
}