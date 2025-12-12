#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"

    //colocando limites no vetor
#define MAX 10 //definido o maximo de animais que podem ser cadastrados
Animal listAnimals[MAX]; //listAnimals é o nome do vetor e MAX é o tamamnho máximo q foi definido
int qtd = 0; //quantidade de animais cadastrados até o momento
//vai ser tipo 
//listAnimals[0]
//listAnimals[1]
//listAnimals[2]
//e cada um deles tera: nome, idade e especie


    //função inserir
void insert () {
    if (qtd>= MAX){ //vai verificar se está cheio
        printf("Lista cheia"); //se tiver, imprimi isso
        return;
    }

    printf("Nome do animal: "); //Isso salva o nome digitado na posição atual do vetor:
    scanf(" %49[^\n]", listAnimals[qtd].nome); //%49[^\n] lê a linha inteira (permite espaço)
        printf("Especie: ");

    scanf(" %49[^\n]", listAnimals[qtd].especie);//listAnimals[qtdd]o produto que está sendo criado
    printf("idade do animal+: ");

    scanf("%d", &listAnimals[qtd].idade); 
   
    qtd++;
    printf("Animal cadastradi com sucesso! ");
//go fuck youself
    //Depois de colocar o animal na posição atual, aumenta o contador
}