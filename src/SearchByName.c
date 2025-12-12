#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void searchByName(){
    if (qtd ==0){
        printf("\nNenhum animal cadastrado!");
        return;
    }
    char nomeBusca[50];
    printf("Digite o nome do animal: ");
    fflush(stdin);
    scanf(" %49[^\n]", nomeBusca);

    for (int i = 0; i < qtd; i++) {
        if (strcmp(listAnimals[i].nome,nomeBusca) == 0) {
            printf("\nAnimal encontrado!");
            printf(" Nome: %s", listAnimals[i].nome);
            printf(" Espécie: %s\n", listAnimals[i].especie);
            printf(" Idade: %d\n", listAnimals[i].idade);
            return;
        }
    }
    printf("\n Animal não encontrado! ");
}