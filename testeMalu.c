#include <stdio.h>

char boba(int receba);

union{ //para facilitar na hora de pegar e passar os valores dos inteiros
    int i;
    unsigned char c[4]; //int -- 4 bytes
} inteiro;

int main (void){
    int receba = 0xFFFFFF01;
    char retorno = boba(receba);
    inteiro.i = 0xABCDEF01;

    printf("\n%02x\n", retorno);
    for (int aux = 0; aux < 4; aux++){
        printf("\n%d - %02x\n",aux, inteiro.c[aux]);
    }
}