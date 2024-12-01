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

    // Teste 1: (PARAM, PARAM, IND)
    int v_z = 5; 
    params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM;
    params[2].tipo_val = INT_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = &v_z;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(3, 4); 
    printf("Teste 1 (PARAM, PARAM, IND): %d\n", resultado);
    if (resultado == minha(3, 4, v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (PARAM, IND, FIX)
    int v_y = 4; 
    params[1].tipo_val = INT_PAR; params[1].orig_val = IND; params[1].valor.v_ptr = &v_y;
    params[2].tipo_val = INT_PAR; params[2].orig_val = FIX; params[2].valor.v_int = 5;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(3); 
    printf("Teste 2 (PARAM, IND, FIX): %d\n", resultado);
    if (resultado == minha(3, v_y, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 3: (IND, IND, IND)
    int v_x = 3, v_y2 = 4, v_z2 = 5; 
    params[0].tipo_val = INT_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = &v_x;
    params[1].tipo_val = INT_PAR; params[1].orig_val = IND; params[1].valor.v_ptr = &v_y2;
    params[2].tipo_val = INT_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = &v_z2;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(); 
    printf("Teste 3 (IND, IND, IND): %d\n", resultado);
    if (resultado == minha(v_x, v_y2, v_z2)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 4: (IND, PARAM, PARAM)
    int v_x2 = 3; 
    params[0].tipo_val = INT_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = &v_x2;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM;
    params[2].tipo_val = INT_PAR; params[2].orig_val = PARAM;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(4, 5); 
    printf("Teste 4 (IND, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(v_x2, 4, 5)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}