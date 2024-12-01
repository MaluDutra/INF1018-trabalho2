#include <stdio.h>
#include <string.h>
#include "cria_func.h"

typedef int (*func_ptr) (void* str2, int n);

int main(void) {
    DescParam params[3];
    func_ptr mesmo_prefixo;
    char prefixo[50] = "teste";
    char outra_string[] = "teste123";
    int tam = strlen(prefixo);
    unsigned char codigo[500];

    params[0].tipo_val = PTR_PAR;
    params[0].orig_val = FIX;
    params[0].valor.v_ptr = prefixo;

    params[1].tipo_val = PTR_PAR;
    params[1].orig_val = PARAM;

    params[2].tipo_val = INT_PAR;
    params[2].orig_val = PARAM;

    cria_func(memcmp, params, 3, codigo);
    mesmo_prefixo = (func_ptr)codigo;

    printf("'%s' tem mesmo prefixo de '%s'? %s\n", outra_string, prefixo,
           mesmo_prefixo(outra_string, tam) ? "NÃO" : "SIM");

    strcpy(prefixo, "outro");
    printf("'%s' tem mesmo prefixo de '%s'? %s\n", outra_string, prefixo,
           mesmo_prefixo(outra_string, tam) ? "NÃO" : "SIM");

    return 0;
}
