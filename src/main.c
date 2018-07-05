#include <stdio.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"

int main()
{
    gmp_randstate_t rand_state;
    gmp_randinit_default(rand_state);
    gmp_randseed_ui(rand_state, 12394781);

    mpz_t n;
    mpz_init_set_ui(n, 25);

    printf("%d\n", probably_prime(n, 4, rand_state));

    mpz_clear(n);

    return 0;
}