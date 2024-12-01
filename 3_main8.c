#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int*);

int minha(int* x, int* y, int* z) {
    return *x + *y * *z;
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    unsigned char codigo[500];
    int a = 3, b = 4, c = 5;
    int* v_a = &a;
    int* v_b = &b;
    int* v_c = &c;
    int** v_v_a = &v_a;
    int** v_v_b = &v_b;
    int** v_v_c = &v_c;

    // Teste 1: (IND, PARAM, IND)
    params[0].tipo_val = PTR_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = v_v_a;
    params[1].tipo_val = PTR_PAR; params[1].orig_val = PARAM; 
    params[2].tipo_val = PTR_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = v_v_c;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int original = minha(&a, &b, &c);
    printf("resultado original: %d\n", original);
    int resultado = f_func(v_b);  
    printf("Teste 1 (IND, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(v_a, v_b, v_c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (IND, PARAM, FIX)
    params[1].tipo_val = PTR_PAR; params[1].orig_val = PARAM; 
    params[2].tipo_val = PTR_PAR; params[2].orig_val = FIX; params[2].valor.v_ptr = v_c;
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    printf("resultado original: %d\n", minha(&a, &b, &c));
    resultado = f_func(v_b);  
    printf("Teste 2 (IND, PARAM, FIX): %d\n", resultado);
    if (resultado == minha(&a, &b, &c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 3: (IND, FIX, PARAM)
    params[0].tipo_val = PTR_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = v_v_a;
    params[1].tipo_val = PTR_PAR; params[1].orig_val = FIX; params[1].valor.v_ptr = &b;
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM; 
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    printf("resultado original: %d\n", minha(&a, &b, &c));
    resultado = f_func(v_c);
    printf("Teste 3 (IND, FIX, PARAM): %d\n", resultado);
    if (resultado == minha(&a, &b, &c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 4: (IND, IND, PARAM)
    params[1].tipo_val = PTR_PAR; params[1].orig_val = IND; params[1].valor.v_ptr = v_v_b;
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM;

    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    resultado = f_func(v_c); 
    printf("resultado original: %d\n", minha(&a, &b, &c)); 
    printf("Teste 4 (IND, IND, PARAM): %d\n", resultado);
    if (resultado == minha(&a,&b,&c)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}
