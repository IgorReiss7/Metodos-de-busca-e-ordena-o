#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void searchByAge(){
    if (qtd ==0){
        printf("\n Nenhum animal dessa idade foi encontrado");
        return;
    }

    char buscarIdade[50];
    printf("\n Digite a idade do animal que deseje buscar: ");
    scanf("%49[^\n]");

    int encontrado = 0;

    for (int i = 0; i <qtd; i++) {
    if (listAnimals[i].idade==buscarIdade){
        encontrado =1;

        printf("\n Animal encontrado! :");
        printf(" Nome: %s\n", listAnimals[i].nome);
        printf(" Espécie: %s\n", listAnimals[i].especie);
        printf(" Idade: %d", listAnimals[i].idade);
    }
    }
}