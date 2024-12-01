#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int, int*);  

int minha(int x, int y, int* z) {
    return x + y * (*z);  
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];

    int x = 3;  
    int y = 5;
    int z = 10;
    int * v_x = &x;
    int * v_y = &y;
    int * v_z = &z;
    int ** v_v_x = &v_x;
    int ** v_v_y = &v_y;
    int ** v_v_z = &v_z; 

    // Teste 1: (IND, PARAM, PARAM)
    params[0].tipo_val = INT_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = v_x;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM; 
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM;  

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(y, v_z);  
    printf("Teste 1 (IND, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(x, y, v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (PARAM, IND, PARAM)
    params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;  
    params[1].tipo_val = INT_PAR; params[1].orig_val = IND; params[1].valor.v_ptr = v_y;

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(x, v_z);  
    printf("Teste 2 (PARAM, IND, PARAM): %d\n", resultado);
    if (resultado == minha(x, y, v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}