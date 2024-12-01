#include <stdio.h>
#include "cria_func.h"

typedef int (*func_ptr) (int x, int y);

int mult(int x, int y, int z) {
  return (x * y) + z;
}

int main (void) {
  DescParam params[3];
  func_ptr f_mult;
  int i;
  unsigned char codigo[500];

  params[0].tipo_val = INT_PAR; 
  //params[0].orig_val = PARAM;  
  params[0].orig_val = FIX;  
  params[0].valor.v_int = 1;
  //params[0].orig_val = IND;
  //params[0].valor.v_ptr = &i;

  params[1].tipo_val = INT_PAR; 
  //params[1].orig_val = PARAM;  
  //params[1].orig_val = FIX;  
  //params[1].valor.v_int = 100;
  params[1].orig_val = IND;
  params[1].valor.v_ptr = &i;

  params[2].tipo_val = INT_PAR; 
  //params[2].orig_val = PARAM; 
  //params[2].orig_val = FIX;     
  //params[2].valor.v_int = 10;
  params[2].orig_val = IND;
  params[2].valor.v_ptr = &i;

  cria_func (mult, params, 3, codigo);
  f_mult = (func_ptr) codigo;   

  for (i = 1; i <=10; i++) {
    if (mult(1, i, i) == f_mult(i, i)){
      printf("%d == %d --> igual!\n",mult(1, i, i), f_mult(i, i)); 
    }
  }

  return 0;
}