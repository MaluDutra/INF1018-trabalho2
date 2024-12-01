#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

int id(int x) {
  return x;
}

int id_ptr(int* x){
  return *x;
}

int main (void) {
  DescParam params[2];
  func_ptr f_func;
  unsigned char codigo[500];
  int x = 5;
  int* v_x = &x;
  int pot = 0;
  int* v_pot = &pot;
  int ** v_v_pot = &v_pot;

  // TESTES COM 1 PARÂMETRO:
  // INTEIRO:
  // Teste 1: (FIX)
  params[0].tipo_val = INT_PAR; params[0].orig_val = FIX; params[0].valor.v_int = x;
  cria_func (id, params, 1, codigo);
  f_func = (func_ptr) codigo;
  int resultado = f_func();
  printf("Teste 1 (INT FIX): %d\n", resultado);
    if (resultado == id(x)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

  // Teste 2: (IND)
  params[0].tipo_val = INT_PAR; params[0].orig_val = IND; params[0].valor.v_ptr = v_pot;
  cria_func (id, params, 1, codigo);
  f_func = (func_ptr) codigo;
  printf("Teste 2: (INT IND): %d\n", resultado);
  for (pot = 0; pot <=  15; pot++) {
    printf("%d\t%d", id(pot), f_func());
    if (f_func() == id(pot)) {
        printf("\t--> oh yeah\n");
    } else {
        printf("\t--> oh shit\n");
    }
  }

  // Teste 3: (PARAM)
  params[0].tipo_val = INT_PAR; params[0].orig_val = PARAM;
  cria_func (id, params, 1, codigo);
  f_func = (func_ptr) codigo;
  resultado = f_func(x);
  printf("Teste 3 (INT PARAM): %d\n", resultado);
    if (resultado == id(x)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

  // PONTEIRO:
  // Teste 1: (FIX)
  params[0].tipo_val = PTR_PAR;  params[0].orig_val = FIX;  params[0].valor.v_ptr = v_x;
  cria_func (id_ptr, params, 1, codigo);
  f_func = (func_ptr) codigo;
  resultado = f_func();
  printf("Teste 1 (PTR FIX): %d\n", resultado);
    if (resultado == id_ptr(v_x)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

  // Teste 2: (IND)
  params[0].tipo_val = PTR_PAR;  params[0].orig_val = IND;  params[0].valor.v_ptr = v_v_pot;
  cria_func (id_ptr, params, 1, codigo);
  f_func = (func_ptr) codigo;
  printf("Teste 2: (PTR IND): %d\n", resultado);
  for (pot = 0; pot <=  15; pot++) {
    printf("%d\t%d", id_ptr(v_pot), f_func());
    if (f_func() == id_ptr(v_pot)) {
        printf("\t--> oh yeah\n");
    } else {
        printf("\t--> oh shit\n");
    }
  }

  // Teste 3: (PARAM)
  params[0].tipo_val = PTR_PAR;  params[0].orig_val = PARAM;
  cria_func (id_ptr, params, 1, codigo);
  f_func = (func_ptr) codigo;
  resultado = f_func(v_x);
  printf("Teste 3 (PTR PARAM): %d\n", resultado);
    if (resultado == id_ptr(v_x)) {
        printf("<PASSOU!>\n");
    } else {
        printf("<xNAO PASSOUx>\n");
    }

  printf("\n");

  return 0;
}