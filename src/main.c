#include <stdio.h>
#include "lib/arithmetics.h"

int main()
{
    mpz_t a;
    mpz_init_set_ui(a, 3);
    mpz_t n;
    mpz_init_set_ui(n, 32);
    mpz_t r;
    mpz_init(r);

    if (modular_inverse(r, a, n)) {
        printf("Has inverse!\n");
    }

    gmp_printf("%Zd\n", a);
    gmp_printf("%Zd\n", n);
    gmp_printf("%Zd\n", r);

    mpz_clear(a);
    mpz_clear(n);
    mpz_clear(r);

    return 0;
}