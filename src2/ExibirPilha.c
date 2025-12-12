#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void display() { 
    if (qtdP == 0){ 
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<== Lista de Animais ==>\n");
    for (int i = 0; i < qtdP; i++) { 
        printf("\n Animal %d\n",i+1);
        printf("Nome: %s\n", pilhaAnimais[i].nome);
        printf("Espécie: %s\n", pilhaAnimais[i].especie);
        printf("Idade: %d\n", pilhaAnimais[i].idade);
    }
}