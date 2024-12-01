#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int);  

int minha(int x, int y, int z) {
    return x + y * z;  
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];

    // Teste 1: (IND, PARAM, IND)
    int v_x = 3;  
    int v_y = 4;  
    int v_z = 5;  
    int* ptr_x = &v_x;  
    int* ptr_z = &v_z;  

    params[0].tipo_val = INT_PAR; params[0].orig_val = IND;  
    params[0].valor.v_ptr = ptr_x;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM; 
    params[2].tipo_val = INT_PAR; params[2].orig_val = IND;  
    params[2].valor.v_ptr = ptr_z;

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(v_y);  // 3 + 4 * 5 = 23
    printf("Teste 1 (IND, PARAM, IND): %d\n", resultado);
    if (resultado == minha(v_x, v_y, v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    //Teste 2: (IND, FIX, PARAM)
    int v_y2 = 6;  
    params[0].tipo_val = INT_PAR; params[0].orig_val = IND;  
    params[0].valor.v_ptr = ptr_x;
    params[1].tipo_val = INT_PAR; params[1].orig_val = FIX;  
    params[1].valor.v_int = v_y2;
    params[2].tipo_val = INT_PAR; params[2].orig_val = PARAM; 
    //params[2].valor.v_int = v_z;

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(v_z);  // 3 + 6 * 5 = 33
    printf("Teste 2 (IND, FIX, PARAM): %d\n", resultado);
    if (resultado == minha(v_x, v_y2, v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}
