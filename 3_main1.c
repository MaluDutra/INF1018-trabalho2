#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int id(int x, int* y, int z){
  return (x+z) * *y;
}

int main (void) {
    DescParam params[3];
    func_ptr f_func;
    int i;
    unsigned char codigo[500];
    int fixo[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int x = 2;
    int* ptr = &fixo[0];
    int** ptr2 = &ptr;
    int z = 3;
    
    params[0].tipo_val = INT_PAR;    params[0].orig_val = FIX;    params[0].valor.v_int = x;
    params[1].tipo_val = PTR_PAR;    params[1].orig_val = IND;    params[1].valor.v_ptr = ptr2;
    params[2].tipo_val = INT_PAR;    params[2].orig_val = FIX;    params[2].valor.v_int = z;

    cria_func (id, params, 3, codigo);
    f_func = (func_ptr) codigo;
    
    for (i = 0; i <=10; i++) {
        printf("%d\t%d\n", id(x, ptr, z), f_func());
        int resultado = f_func();
        if (resultado == id(x, ptr, z)) {
            printf("<PASSOU!>\n");
        } else {
            printf("<xNAO PASSOUx>\n");
        }
        ptr++;
    }

    return 0;
}