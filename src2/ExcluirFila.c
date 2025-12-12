#include <stdio.h>
#include "Animal.h"
#include <string.h>
#include "globals.h"
void ExcluirFila(Animal filaAnimais[]){
    if (qtd>0){
        for(int i=0; i<qtd; i++){
            strcpy (filaAnimais[i].nome, filaAnimais[i+1].nome);
            strcpy (filaAnimais[i].especie, filaAnimais[i+1].especie);
            filaAnimais[i].idade = filaAnimais[i+1].idade;
        }
        qtd--;
    } else{
        printf("não há mais animais para serem excluidos");
    }
}
