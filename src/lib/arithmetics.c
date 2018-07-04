#include <gmp.h>
#include "arithmetics.h"

void mdc_estendido(mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b)
{
    // Init values
    mpz_t r;
    mpz_init(r);
    mpz_t q;
    mpz_init(q);
    mpz_t aux;
    mpz_init(aux);

    mpz_mod(r, a, b); // r = a % b
    mpz_div(q, a, b); // q = a / b

    // r == 0 => g = b
    //        => a*x + b*y = b
    //        => x = 0, y = 1
    if (!mpz_cmp_ui(r, 0))
    {
        mpz_set_ui(x, 0);
        mpz_set_ui(y, 1);
        goto end;
    }

    // b*x' + r*y' == gcf(b, r) == gcf(a, b)
    mdc_estendido(g, x, y, b, r);

    // b*x' + r*y' == b*x' + (a - b*q)*y'
    //             == b*x' + a*y' - b*q*y'
    //             == a*y' + b*(x' - q*y') == gcf(a, b)
    mpz_mul(aux, q, y);
    mpz_sub(aux, x, aux);
    mpz_set(x, y);   // x = y'
    mpz_set(y, aux); // y = (x' - q*y')

end:
    // g = a*x + b*y
    mpz_mul(g, a, x);
    mpz_mul(aux, b, y);
    mpz_add(g, g, aux);

    // Clear values
    mpz_clear(r);
    mpz_clear(q);
    mpz_clear(aux);
}