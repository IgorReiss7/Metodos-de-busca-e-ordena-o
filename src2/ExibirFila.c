#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void display() { 
    if (qtdF == 0){ 
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<== Lista de Animais ==>\n");
    for (int i = 0; i < qtdF; i++) { 
        printf("\n Animal %d\n",i+1);
        printf("Nome: %s\n", filaAnimais[i].nome);
        printf("Espécie: %s\n", filaAnimais[i].especie);
        printf("Idade: %d\n", filaAnimais[i].idade);
    }
}