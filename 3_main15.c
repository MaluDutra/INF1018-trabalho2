#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int ,int, int*);
typedef int (*func2_ptr) (int, int);
typedef int (*func3_ptr) (int, int*);

int minha(int x, int y, int* z) {
    return x + y * (*z);
}

int main(void) {
    DescParam params[3];
    func_ptr f_func;
    func2_ptr f_func2;
    func3_ptr f_func3;
    unsigned char codigo[500];

    // Teste 1: (PARAM, PARAM, PARAM)
    int v_z = 5; 
    params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;
    params[1].tipo_val = INT_PAR; params[1].orig_val = PARAM;
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM; 
    cria_func(minha, params, 3, codigo);
    f_func = (func_ptr)codigo;
    int resultado = f_func(3, 4, &v_z); // 3 + 4 * (*5) = 23
    printf("Teste 1 (PARAM, PARAM, PARAM): %d\n", resultado);
    if (resultado == minha(3, 4, &v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 2: (PARAM, PARAM, FIX)
    params[2].tipo_val = PTR_PAR; params[2].orig_val = FIX; params[2].valor.v_ptr = &v_z;
    cria_func(minha, params, 3, codigo);
    f_func2 = (func2_ptr)codigo;
    resultado = f_func2(3, 4); // 3 + 4 * (*5) = 23
    printf("Teste 2 (PARAM, PARAM, FIX): %d\n", resultado);
    if (resultado == minha(3, 4, &v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }
    int* v_a = &v_z;
    // Teste 3: (PARAM, PARAM, IND)
    int** v_z2 = &v_a; // variável para o IND
    params[2].tipo_val = PTR_PAR; params[2].orig_val = IND; params[2].valor.v_ptr = v_z2;
    cria_func(minha, params, 3, codigo);
    f_func2 = (func2_ptr)codigo;
    resultado = f_func2(3, 4); // 3 + 4 * (*6) = 27
    printf("Teste 3 (PARAM, PARAM, IND): %d\n", resultado);
    if (resultado == minha(3, 4, &v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    // Teste 4: (PARAM, FIX, PARAM)
    int v_y = 5; // variável para o FIX
    params[1].tipo_val = INT_PAR; params[1].orig_val = FIX; params[1].valor.v_int = v_y;
    params[2].tipo_val = PTR_PAR; params[2].orig_val = PARAM;
    cria_func(minha, params, 3, codigo);
    f_func3 = (func3_ptr)codigo;
    printf("resultado original: %d\n", minha(3, v_y, &v_z));
    resultado = f_func3(3,&v_z); // 3 + 5 * (*5) = 28
    printf("Teste 4 (PARAM, FIX, PARAM): %d\n", resultado);
    if (resultado == minha(3, v_y, &v_z)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }
    return 0;
}