#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void searchBySpecies(){
    if (qtd ==0){
        printf("Nenhum animal cadastrado");
        return;
    }
    char buscarEspecie[50];
    printf("\nDigite a espécie do animal que deseje buscar: ");
    scanf(" %49[^\n]",buscarEspecie);

    int encontrado = 0;

      for (int i = 0; i < qtd; i++) {
        if (strcmp(listAnimals[i].especie, buscarEspecie)==0) {
            encontrado = 1;
            printf("\nAnimal encontrado!\n");
            printf(" Nome: %s\n", listAnimals[i].nome);
            printf(" Espécie: %s\n", listAnimals[i].especie);
            printf(" Idade: %d\n", listAnimals[i].idade);
        }
    }
     if (!encontrado) {
        printf("\nNenhum animal dessa espécie foi encontrado.");
    }
}