 #include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void search(){
    if (qtd ==0) {
        printf("Nenhum animal foi encontradio");
        return;
    }

    char buscarNome[50];
    printf("Digite o nome do animal que deseja buscar: ");
    scanf("%49[^\n]", buscarNome);
    int encontrado = -1;

    //busca linear 

    for (int i =0; i<qtd;i++) {
        if (strcmp(listAnimals[i].nome, buscarNome) == 0) { //Você compara nome por nome até achar.
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1){
        printf("Animal não encontrado :( ");
    }
    else {
        printf("\n Animal encontrado! ");
        printf("Nome: %s",listAnimals[encontrado].nome);
        printf(" Espécie: %s\n", listAnimals[encontrado].especie);
        printf(" Idade: %d", listAnimals[encontrado].idade);
    }
}