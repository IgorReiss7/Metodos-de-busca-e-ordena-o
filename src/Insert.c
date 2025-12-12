#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"
#include "globals.h"   

void insert() {
    if (qtd >= MAX) {
        printf("Lista cheia\n");
        return;
    }

    printf("Nome do animal: ");
    scanf(" %49[^\n]", listAnimals[qtd].nome);

    printf("Especie: ");
    scanf(" %49[^\n]", listAnimals[qtd].especie);

    printf("Idade do animal: ");
    scanf("%d", &listAnimals[qtd].idade);

    qtd++;
    printf("Animal cadastrado com sucesso!\n");
}
