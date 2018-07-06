#include <stdio.h>
#include <stdlib.h>
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

    gmp_printf("n = %Zd e = %Zd d = %Zd\n", n, e, d);
    
    mpz_t M;
    mpz_init(M);

    char str[] = "danilo pimentel de carvalho costa";
    encode(M, str);

    gmp_printf("encode: M = %Zd\n", M);

    mpz_t C;
    mpz_init(C);

    encrypt(C, M, n, e);

    gmp_printf("encrypt: C = %Zd\n", C);

    decrypt(M, C, n, d);

    gmp_printf("decrypt: M = %Zd\n", M);

    char *decoded = decode(M);
    printf("decode: %s\n", decoded);

    free(decoded);
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(M);
    mpz_clear(C);
    gmp_randclear(randstate);

    return 0;
}