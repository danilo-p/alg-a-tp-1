#include <stdio.h>
#include <stdlib.h>
#include "lib/arithmetics.h"
#include "lib/primality.h"
#include "lib/rsa.h"

int main()
{
    mpz_t r;
    mpz_init(r);
    char str[] = "danilo pimentel de carvalho costa";
    encode(r, str);
    char *decoded = decode(r);
    gmp_printf("%Zd %s\n", r, decoded);
    mpz_clear(r);
    free(decoded);
    return 0;
}