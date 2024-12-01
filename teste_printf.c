#include <stdio.h>
#include <string.h>
#include "cria_func.h"

typedef int (*func_ptr) ();

char fixa[] = "printando %p - %d\n";

int main (void) {
  DescParam params[3];
  func_ptr print2;
  unsigned char codigo[500];

  int i = 23;
  int* end = &i;

  char* end_fixa = fixa;

  params[0].tipo_val = PTR_PAR; 
  params[0].orig_val = IND;     
  params[0].valor.v_ptr = &end_fixa;

  params[1].tipo_val = PTR_PAR; 
  params[1].orig_val = IND;
  params[1].valor.v_ptr = &end;   

  params[2].tipo_val = INT_PAR; 
  params[2].orig_val = IND;
  params[2].valor.v_ptr = &i;

  cria_func (printf, params, 3, codigo);
  print2 = (func_ptr) codigo;



  print2();
  printf("printando %p - %d\n", &i, i);

  return 0;
}


