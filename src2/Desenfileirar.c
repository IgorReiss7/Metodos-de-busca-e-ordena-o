#include <stdio.h>
#include "Animal.h"
#include <string.h>
#include "globals.h"
void Desenfileirar(){
    if (qtdF>0){
        if (qtdP<MAX){
        pilhaAnimais[qtdP]=filaAnimais[0];
        qtdP++;
        }
        else{
            printf("não é possivel desenfileirar pois a pilha já está cheia");
        }
        for(int i=0; i<qtdF-1; i++){
            strcpy (filaAnimais[i].nome, filaAnimais[i+1].nome);
            strcpy (filaAnimais[i].especie, filaAnimais[i+1].especie);
            filaAnimais[i].idade = filaAnimais[i+1].idade;
        }
        qtdF--;
    } else{
        printf("não há mais animais para serem excluidos");
    }
}