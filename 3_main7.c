#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int, int*, int*);  

int minha(int x, int* y, int* z) {
    return x + *y * *z;  
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];

    // Teste 1: (PARAM, PARAM, PARAM)
    int v_x = 3;  
    int v_y = 4;  
    int v_z = 5;  

    params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;   
    params[1].tipo_val = PTR_PAR; params[1].orig_val = PARAM; 
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM;   

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(v_x, &v_y, &v_z);  
    printf("Teste 1 (PARAM, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(v_x, &v_y, &v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}
