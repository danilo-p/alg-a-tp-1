#include <stdio.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"
#include "lib/rsa.h"

int main()
{
    gmp_randstate_t randstate;
    gmp_randinit_default(randstate);
    gmp_randseed_ui(randstate, 134143134);

    mpz_t n;
    mpz_init(n);

    mpz_t e;
    mpz_init(e);

    mpz_t d;
    mpz_init(d);

    key_gen(n, e, d, randstate);

    gmp_printf("%Zd %Zd %Zd\n", n, e, d);

    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
    gmp_randclear(randstate);

    return 0;
}