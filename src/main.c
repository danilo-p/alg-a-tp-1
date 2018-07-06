#include <stdio.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"

int main()
{
    gmp_randstate_t randstate;
    gmp_randinit_default(randstate);
    // gmp_randseed_ui(randstate, 1234567890);

    mpz_t r;
    mpz_init(r);

    random_prime(r, 100, randstate);
    gmp_printf("%Zd %d\n", r, mpz_probab_prime_p(r, 10));

    mpz_clear(r);
    gmp_randclear(randstate);

    return 0;
}