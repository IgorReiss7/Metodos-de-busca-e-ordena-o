#ifndef ANIMAL_H
#define ANIMAL_H

#define MAX 10
typedef struct {
    char nome[50];
    char especie[50];
    int idade;
} Animal;

// Variáveis globais
extern Animal listAnimals[MAX];
extern int qtd;

// Funções
void insert();
void display();
void exclude();
void search();
void searchByName();
void searchBySpecies();
void searchByAge();

void ordering1();   // BubbleSort
void ordering2();   // SelectionSort
void ordering3();   // InsertionSort

#endif
