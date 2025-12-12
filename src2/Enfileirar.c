#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"
#include "globals.h"
Animal filaAnimais[MAX]; 
void enfileirar () {
    if (qtdF>= MAX){
        printf("Lista cheia"); 
        return;
    }

    printf("Nome do animal: ");
    scanf(" %49[^\n]", pilhaAnimais[qtdF].nome);

    printf("Especie: ");
    scanf(" %49[^\n]", pilhaAnimais[qtdF].especie);

    printf("idade do animal+: ");
    scanf("%d", &pilhaAnimais[qtdF].idade); 
   
    qtdF++;
    printf("Animal cadastrado com sucesso! ");
}