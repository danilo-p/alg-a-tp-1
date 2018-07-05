#include <gmp.h>
#include "arithmetics.h"

void gcd_extended(mpz_t g, mpz_t x, mpz_t y,
                  const mpz_t a, const mpz_t b)
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
    if (mpz_cmp_ui(r, 0) == 0)
    {
        mpz_set_ui(x, 0);
        mpz_set_ui(y, 1);
        goto end;
    }

    // b*x' + r*y' == gcf(b, r) == gcf(a, b)
    gcd_extended(g, x, y, b, r);

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

int modular_inverse(mpz_t r,
                    const mpz_t a,
                    const mpz_t n)
{

    mpz_t g;
    mpz_init(g);
    mpz_t x;
    mpz_init(x);
    mpz_t a_mod_n;
    mpz_init(a_mod_n);
    int has_inverse = 0;

    mpz_mod(a_mod_n, a, n); // Avoids a greater than n

    gcd_extended(g, x, r, n, a_mod_n);

    if (mpz_cmp_ui(g, 1) == 0)
    {
        has_inverse = 1;
    }

    mpz_clear(g);
    mpz_clear(x);
    mpz_clear(a_mod_n);
    return has_inverse;
}

void binary_exp(mpz_t r,
                const mpz_t b,
                const mpz_t e,
                const mpz_t n)
{
    mpz_t i;
    mpz_init_set(i, e);

    mpz_t x;
    mpz_init(x);
    mpz_mod(x, b, n);

    mpz_set_ui(r, 1);

    while (mpz_cmp_ui(i, 0) > 0)
    {
        if (mpz_odd_p(i))
        {
            mpz_mul(r, r, x);
            mpz_mod(r, r, n);
        }

        mpz_div_ui(i, i, 2);
        mpz_mul(x, x, x);
        mpz_mod(x, x, n);
    }

    mpz_clear(i);
    mpz_clear(x);
}