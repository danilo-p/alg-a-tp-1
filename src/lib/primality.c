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
    if (mpz_cmp_ui(r, 0) == 0) {
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