#include <stdio.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"
#include "lib/rsa.h"

int main()
{
    mpz_t r;
    mpz_init(r);
    char str[] = "Danilo";
    encode(r, str);
    gmp_printf("%Zd\n", r);
    mpz_clear(r);
    return 0;
}