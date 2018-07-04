#include <stdio.h>
#include "lib/arithmetics.h"

int main()
{
    mpz_t g;
    mpz_init(g);
    mpz_t x;
    mpz_init(x);
    mpz_t y;
    mpz_init(y);
    mpz_t a;
    mpz_init_set_ui(a, 15);
    mpz_t b;
    mpz_init_set_ui(b, 10);

    mdc_estendido(g, x, y, a, b);

    gmp_printf("%Zd\n", g);
    gmp_printf("%Zd\n", x);
    gmp_printf("%Zd\n", y);
    gmp_printf("%Zd\n", a);
    gmp_printf("%Zd\n", b);

    mpz_clear(g);
    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(a);
    mpz_clear(b);

    return 0;
}