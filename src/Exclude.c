#include <stdio.h>
#include <string.h>
#include "Animal.h"
#include "globals.h"

void exclude() {
    if (qtd==0){
        printf("Nenhum animal foi cadastrado ainda");
        return; //Num dá pra excluir nada se não tiver nada
    }

    char nomeBuscar[50];
    printf("Digite o nome do animal que deseja excluir: ");
    scanf(" %49[^\n]", nomeBuscar);

    int index = -1;

    // Procurando pelo nome
    for (int i = 0; i < qtd; i++) {
        if (strcmp(listAnimals[i].nome, nomeBuscar) ==0) { //Compara com strcmp
            index = i; //Se encontrar ele vai guardar o índice
            break;
        }
    }
    
    if (index == -1) {
        printf("\nAnimal não encontrado.");
        return;
    }
         // Deslocando todos para trás
        for (int i = index; i < qtd-1; i++) { //Empurra todo mundo para a esquerda.
        listAnimals[i]=listAnimals[i + 1];
        }
        qtd--; // diminui a quantidade

        printf("Animal foi excluido com sucesso!");
    
}