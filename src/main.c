#include <stdio.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"

int main()
{
    mpz_t a;
    mpz_init_set_ui(a, 2);
    mpz_t n;
    mpz_init_set_ui(n, 561);
    mpz_t n1;
    mpz_init_set_ui(n1, 560);
    unsigned int t;
    t = 4;
    mpz_t q;
    mpz_init_set_ui(q, 35);

    printf("\n\n\n%d\n", maybe_prime(a, n, n1, t, q));

    mpz_clear(a);
    mpz_clear(n);
    mpz_clear(n1);
    mpz_clear(q);

    return 0;
}