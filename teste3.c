#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int mult(int x, int y) {
    return x * y;
}

int main(void) {
    DescParam params[2];
    func_ptr f_mult;
    int x = 3;
    unsigned char codigo[500];

    params[0].tipo_val = INT_PAR;
    params[0].orig_val = IND;
    params[0].valor.v_ptr = &x;

    params[1].tipo_val = INT_PAR;
    params[1].orig_val = FIX;
    params[1].valor.v_int = 4;

    cria_func(mult, params, 2, codigo);
    f_mult = (func_ptr)codigo;

    printf("Multiplicação (%d * 4) = %d\n", x, f_mult());
    x = 10;
    printf("Multiplicação (%d * 4) = %d\n", x, f_mult());

    return 0;
}
