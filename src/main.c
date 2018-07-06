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

    gmp_printf("\nPublic key: (n = %Zd, e = %Zd)\n", n, e);
    gmp_printf("\nPrivate key: (n = %Zd, d = %Zd)\n", n, d);

    mpz_t M;
    mpz_init(M);

    char str[] = "Danilo Pimentel de Carvalho Costa";
    encode(M, str);

    gmp_printf("\nOriginal message: %s\n", str);
    gmp_printf("\nEncoded message: %Zd\n", M);

    mpz_t C;
    mpz_init(C);

    encrypt(C, M, n, e);

    gmp_printf("\nEncrypted message: %Zd\n", C);

    decrypt(M, C, n, d);

    gmp_printf("\nDecrypted message: %Zd\n", M);

    char *decoded = decode(M);
    gmp_printf("\nDecoded message: %s\n", decoded);

    free(decoded);
    mpz_clear(n);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(M);
    mpz_clear(C);
    gmp_randclear(randstate);

    return 0;
}