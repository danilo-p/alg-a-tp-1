#include <stdio.h>
#include "lib/arithmetics.h"

int main()
{
    mpz_t r;
    mpz_init(r);
    mpz_t b;
    mpz_init_set_ui(b, 2);
    mpz_t e;
    mpz_init_set_ui(e, 6);
    mpz_t n;
    mpz_init_set_ui(n, 10);

    binary_exp(r, b, e, n);

    gmp_printf("%Zd\n", r);

    mpz_clear(r);
    mpz_clear(b);
    mpz_clear(e);
    mpz_clear(n);

    return 0;
}