#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void searchByAge() {
    if (qtd == 0) {
        printf("\nNenhum animal cadastrado.\n");
        return;
}
    int buscarIdade;
    printf("\nDigite a idade que deseja buscar: ");
    scanf("%d", &buscarIdade);

    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (listAnimals[i].idade == buscarIdade) {
            encontrado = 1;
            printf("\nAnimal encontrado!\n");
            printf("Nome: %s\n", listAnimals[i].nome);
            printf("Espécie: %s\n", listAnimals[i].especie);
            printf("Idade: %d\n", listAnimals[i].idade);
        }
    }
    if (!encontrado) {
        printf("\nNenhum animal com essa idade foi encontrado.\n");
    }
}
