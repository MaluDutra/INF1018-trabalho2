#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr)(int b);

int calc(int a, int b, int c) {
    return a * b + c;
}

int main(void) {
    DescParam params[3];
    func_ptr f_calc;
    int c = 10;
    unsigned char codigo[500];

    params[0].tipo_val = INT_PAR;
    params[0].orig_val = FIX;
    params[0].valor.v_int = 5;

    params[1].tipo_val = INT_PAR;
    params[1].orig_val = PARAM;

    params[2].tipo_val = INT_PAR;
    params[2].orig_val = IND;
    params[2].valor.v_ptr = &c;

    cria_func(calc, params, 3, codigo);
    f_calc = (func_ptr)codigo;

    printf("Resultado = %d\n", f_calc(2));
    c = 20;
    printf("Resultado = %d\n", f_calc(3));

    return 0;
}
