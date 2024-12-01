#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int minha(int x, int y, int z) {
    return x + y * z;
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];

    // Teste 1: (PARAM, PARAM, PARAM)
    params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM;
    params[2].tipo_val = INT_PAR; params[2].orig_val = PARAM;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(3, 4, 5); // 3 + 4 * 5 = 23
    printf("Teste 1 (PARAM, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(3, 4, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (PARAM, PARAM, FIX)
    params[2].tipo_val = INT_PAR; params[2].orig_val = FIX; params[2].valor.v_int = 5; 
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(3, 4); // 3 + 4 * 5 = 23
    printf("Teste 2 (PARAM, PARAM, FIX): %d\n", resultado);
    if (resultado == minha(3, 4, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 3: (PARAM, FIX, PARAM)
    params[1].tipo_val = INT_PAR; params[1].orig_val = FIX; params[1].valor.v_int = 4; 
    params[2].tipo_val = INT_PAR; params[2].orig_val = PARAM; 
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(3, 5); // 3 + 4 * 5 = 23
    printf("Teste 3 (PARAM, FIX, PARAM): %d\n", resultado);
    if (resultado == minha(3, 4, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 4: (PARAM, FIX, FIX)
    params[2].tipo_val = INT_PAR; params[2].orig_val = FIX; params[2].valor.v_int = 5; 
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(3); // 3 + 4 * 5 = 23
    printf("Teste 4 (PARAM, FIX, FIX): %d\n", resultado);
    if (resultado == minha(3, 4, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}