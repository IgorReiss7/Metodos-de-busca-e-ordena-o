#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "Insert.h"
#include "globals.h"

void display() { //Testa se NÃO tem animais cadastrados
    if (qtd == 0){ //significa que nenhuma posição do vetor foi usada.
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<== Lista de Animais ==>\n");
    for (int i = 0; i < qtd; i++) { //começa do 0, vai até o índice qtd - 1 e percorrendo somente os animais cadastrados
        printf("\n Animal %d\n",i+1); //Mostra o número do animal na lista (começando do 1, não do 0).
        printf("Nome: %s\n", listAnimals[i].nome);
        printf("Especie: %s\n", listAnimals[i].especie);
        printf("Idade: %d\n", listAnimals[i].idade);
    }
}