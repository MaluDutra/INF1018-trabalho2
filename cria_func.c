/* Gustavo Rocha Barros 2310505 3WA */
/* Maria Luiza Dutra Gonzalez de Almeida 2310509 3WA */
#include <stdio.h>
#include "cria_func.h"

void cria_func(void* f, DescParam params[], int n, unsigned char codigo[]){
    int pos = 0;

    //registro de ativação
    codigo[pos++] = 0x55; 
    codigo[pos++] = 0x48;
    codigo[pos++] = 0x89;
    codigo[pos++] = 0xe5;

    for (int i = 0; i < n; i++){ //preparando os parâmetros para a chamada
        if (params[i].tipo_val == INT_PAR){ //parâmetro é um inteiro
            if (params[i].orig_val == PARAM){
                //é um parâmetro não amarrado
            } else if (params[i].orig_val == FIX){
                //é um parâmetro fixo
            } else{
                //é um endereço
            }

        } else{ //parâmetro é um ponteiro
            if (params[i].orig_val == PARAM){
                //é um parâmetro não amarrado
            } else if (params[i].orig_val == FIX){
                //é um parâmetro fixo
            } else{
                //é um endereço
            }
        }
    }

    //call *%rax
    codigo[pos++] = 0xff;
    codigo[pos++] = 0xd0;
    codigo[pos++] = 0xc9; //leave
    codigo[pos++] = 0xc3; //ret
}