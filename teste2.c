#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int soma(int x, int y) {
    return x + y;
}

int main(void) {
    DescParam params[2];
    func_ptr f_soma;
    int a = 5, b = 7;
    unsigned char codigo[500];

    params[0].tipo_val = INT_PAR;
    params[0].orig_val = IND;
    params[0].valor.v_ptr = &a;

    params[1].tipo_val = INT_PAR;
    params[1].orig_val = IND;
    params[1].valor.v_ptr = &b;

    cria_func(soma, params, 2, codigo);
    f_soma = (func_ptr)codigo;

    printf("Soma(%d, %d) = %d\n", a, b, f_soma());
    a = 10;
    b = 20;
    printf("Soma(%d, %d) = %d\n", a, b, f_soma());

    return 0;
}
