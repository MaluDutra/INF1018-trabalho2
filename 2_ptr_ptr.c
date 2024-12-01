#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int mult(int *x, int *y) {
  return *y * (*x);
}

int main (void) {
    DescParam params[2];
    func_ptr f_func;
    int i;
    int* pi = &i;
    int** ppi = &pi;
    unsigned char codigo[500];
    int x = 2;
    int y = 3;
    int* py = &y;

    //   - (PARAM, PARAM)
    params[0].tipo_val = PTR_PAR;  params[0].orig_val = PARAM;
    params[1].tipo_val = PTR_PAR;  params[1].orig_val = PARAM;

    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;

    int resultado = f_func(&x, &y);  
    printf("Teste 1 (PARAM, PARAM): %d\n", resultado);
    if (resultado == mult(&x,&y)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }
    
    //   - (PARAM, FIX)
    params[1].tipo_val = PTR_PAR;  params[1].orig_val = FIX; params[1].valor.v_ptr = &y;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;

    resultado = f_func(&x);  
    printf("Teste 2 (PARAM, FIX): %d\n", resultado);
    if (resultado == mult(&x,&y)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    //   - (PARAM, IND)
    params[1].tipo_val = PTR_PAR;  params[1].orig_val = IND; params[1].valor.v_ptr = ppi;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;

    printf("Teste 3 (PARAM, IND):\n");
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", f_func(&x), mult(&x,pi));
        if (f_func(&x) == mult(&x,pi)) {
            printf("\t--> oh &yeah\n");
        } else {
            printf("\t--> oh shit\n");
        }
    }

    //   - (IND, IND)
    params[0].tipo_val = PTR_PAR;  params[0].orig_val = IND; params[0].valor.v_ptr = ppi;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;

    printf("Teste 4 (IND, IND):\n");
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", f_func(), mult(pi,pi));
        if (f_func() == mult(pi,pi)) {
            printf("\t--> oh &yeah\n");
        } else {
            printf("\t--> oh shit\n");
        }
    }

    //   - (FIX, IND)
    params[0].tipo_val = PTR_PAR;  params[0].orig_val = FIX; params[0].valor.v_ptr = &x;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;

    printf("Teste 5 (FIX, IND):\n");
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", f_func(), mult(&x,pi));
        if (f_func() == mult(&x,pi)) {
            printf("\t--> oh &yeah\n");
        } else {
            printf("\t--> oh shit\n");
        }
    }

    //   - (FIX, FIX)
    params[1].tipo_val = PTR_PAR;  params[1].orig_val = FIX; params[1].valor.v_ptr = py;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;
    resultado = f_func();
    printf("Teste 6 (FIX, FIX):\n");
    if (resultado == mult(&x,&y)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    //   - (IND, FIX)
    params[0].tipo_val = PTR_PAR;  params[0].orig_val = IND; params[0].valor.v_ptr = ppi;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;
    printf("Teste 7 (IND, FIX):\n");
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", f_func(), mult(pi,&y));
        if (f_func() == mult(pi,&y)) {
            printf("\t--> oh &yeah\n");
        } else {
            printf("\t--> oh shit\n");
        }
    }

    //   - (IND, PARAM)
    params[1].tipo_val = PTR_PAR;  params[1].orig_val = PARAM;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;
    printf("Teste 8 (IND, PARAM):\n");
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", f_func(&y), mult(pi,&y));
        if (f_func(&y) == mult(pi,&y)) {
            printf("\t--> oh &yeah\n");
        } else {
            printf("\t--> oh shit\n");
        }
    }

    //   - (FIX, PARAM)
    params[0].tipo_val = PTR_PAR;  params[0].orig_val = FIX; params[0].valor.v_ptr = &x;
    cria_func (mult, params, 2, codigo);
    f_func = (func_ptr) codigo;
    printf("Teste 9 (FIX, PARAM):\n");
    resultado = f_func(&y);
    if (resultado == mult(&x,&y)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

    return 0;
}