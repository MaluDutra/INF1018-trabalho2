/* Gustavo Rocha Barros 2310505 3WA */
/* Maria Luiza Dutra Gonzalez de Almeida 2310509 3WA */
#include <stdio.h>
#include "cria_func.h"

void cria_func(void* f, DescParam params[], int n, unsigned char codigo[]){
    union{ //para facilitar na hora de pegar e passar os valores dos inteiros
        int i;
        char c[4]; //int -- 4 bytes
    } inteiro;

    union{ //para facilitar na hora de pegar e passar os valores dos ponteiros
        void* p;
        char c[8]; //ponteiro -- 8 bytes
    } ponteiro;

    unsigned char reg_temp[3][3]={{0xf8, 0xf9, 0xfa}, //mover %xdi para %r8, %r9 e %r10
                                      {0xf0, 0xf1, 0xf2},  //mover %xsi para %r8, %r9 e %r10
                                      {0xd0, 0xd1, 0xd2}}; //mover %xdx para %r8, %r9 e %r10

    unsigned char reg_fix_l[3] = {0xb8, 0xb9, 0xba}; //mover $x para %r8d, %r9d e %r10d
    //início
    int pos = 0;

    //registro de ativação
    codigo[pos++] = 0x55; 
    codigo[pos++] = 0x48;
    codigo[pos++] = 0x89;
    codigo[pos++] = 0xe5;

    //salvando os registradores
    //xdi --> r8
    //xsi --> r9
    //xdx --> r10
    int aux_param = 0;
    for (int i = 0; i < n; i++, aux_param++){ 
        if (params[i].tipo_val == INT_PAR){ //parâmetro é um inteiro
            if (params[i].orig_val == PARAM){
                //é um parâmetro não amarrado -- 4 bytes
                codigo[pos++] = 0x41;
                codigo[pos++] = 0x89;
                codigo[pos++] = reg_temp[aux_param][i];

            } else if (params[i].orig_val == FIX){
                //é um parâmetro fixo -- 4 bytes
                codigo[pos++] = 0x41;
                codigo[pos++] = reg_fix_l[i];

                inteiro.i = params[i].valor.v_int;
                for (int aux = 0; aux < 4; aux++){
                    codigo[pos++] = inteiro.c[aux];
                }


            } else if (params[i].orig_val == IND){
                //é um endereço que deve ser guardado -- 8 bytes
                //nsei de jeito nenhum ainda

            }

        } else{ //parâmetro é um ponteiro
            if (params[i].orig_val == PARAM){
                //é um parâmetro não amarrado -- 8 bytes
                codigo[pos++] = 0x49;
                codigo[pos++] = 0x89;
                codigo[pos++] = reg_temp[aux_param][i];

            } else if (params[i].orig_val == FIX){
                //é um parâmetro fixo -- 8 bytes
                //nsei de jeito nenhum ainda


            } else if (params[i].orig_val == IND){
                //é um endereço -- 8 bytes
                //nsei de jeito nenhum ainda


            }
        }
    }

    //call *%rax
    codigo[pos++] = 0xff;
    codigo[pos++] = 0xd0;

    codigo[pos++] = 0xc9; //leave
    codigo[pos++] = 0xc3; //ret
}