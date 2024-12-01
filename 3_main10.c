#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int minha(int* x, int* y, int z) {
    return *x + *y * z;
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];
    int a = 3;
    int b = 4;
    int c = 5;
    int * v_a = &a;
    int * v_b = &b;
    int * v_c = &c;
    int ** v_v_a = &v_a;
    int ** v_v_b = &v_b;
    int ** v_v_c = &v_c;

    // Teste 1: (IND, FIX, IND)
    params[0].tipo_val = PTR_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = v_v_a;
    params[1].tipo_val = PTR_PAR; params[1].orig_val = FIX; params[1].valor.v_ptr = v_b;
    params[2].tipo_val = INT_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = v_c;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func();  
    printf("Teste 1 (IND, FIX, IND): %d\n", resultado);
    if (resultado == minha(&a, &b, c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (IND, IND, FIX)
    params[1].tipo_val = PTR_PAR; params[1].orig_val = IND; params[1].valor.v_ptr = v_v_b;
    params[2].tipo_val = INT_PAR; params[2].orig_val = FIX; params[2].valor.v_int = c;

    f_func = (func_ptr)codigo;
    resultado = f_func(); 
    printf("Teste 2 (IND, IND, FIX): %d\n", resultado);
    if (resultado == minha(&a, &b, c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 3: (IND, IND, IND)
    params[2].tipo_val = INT_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = v_c;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func();  
    printf("Teste 3 (IND, IND, IND): %d\n", resultado);
    if (resultado == minha(&a, &b, c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}
