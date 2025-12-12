#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"
#include "globals.h"
Animal pilhaAnimais[MAX]; 
void empilhar () {
    if (qtdP>= MAX){
        printf("Lista cheia"); 
        return;
    }

    printf("Nome do animal: ");
    scanf(" %49[^\n]", pilhaAnimais[qtdP].nome);

    printf("Especie: ");
    scanf(" %49[^\n]", pilhaAnimais[qtdP].especie);

    printf("idade do animal+: ");
    scanf("%d", &pilhaAnimais[qtdP].idade); 
   
    qtdP++;
    printf("Animal cadastrado com sucesso! ");
}