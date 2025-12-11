#include <stdio.h>
#include <string.h>
#include "Animal.h"
typedef struct Animal  
{ //imaginem criar uma classe em java com seus atributos
    char nome[50];
    char especie[50];
    int idade;
} Animal; //feito o struct (nosso caso será "animal")  

#define MAX 10 //definido o maximo de animais que podem ser cadastrados
Animal listAnimals[MAX]; //listAnimals é o nome do vetor e MAX é o tamamnho máximo q foi definido
int qtd = 0; //quantidade de animais cadastrados até o momento
//vai ser tipo 
//listAnimals[0]
//listAnimals[1]
//listAnimals[2]
//e cada um deles tera: nome, idade e especie
void insert();
void display();
void excluir();
    //função inserir









