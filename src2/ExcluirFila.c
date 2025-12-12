#include <stdio.h>
#include "Animal.h"
#include <string.h>
int qtd = 6;
Animal filaAnimais[10] = {
    {"totó","cachorro",14},
    {"amora","gata",3},
    {"mike","lagarto",5},
    {"algodao","coelho",9},
    {"donatello","tartaruga",8000},
    {"filhodaputa","cavalo",2}
};


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
int main (){
    ExcluirFila(filaAnimais);
    ExcluirFila(filaAnimais);
    ExcluirFila(filaAnimais);
    ExcluirFila(filaAnimais);
    ExcluirFila(filaAnimais);
    ExcluirFila(filaAnimais);
    for (int i=0; i<qtd; i++){
        printf("%s - %s - %d\n",
           filaAnimais[i].nome,
           filaAnimais[i].especie,
           filaAnimais[i].idade);
}
    return 0;
}