#include <string.h>
#include <stdio.h>
#include "Animal.h"
#include "globals.h"

void ordering3() {
    if (qtd <2) {
        printf("\nPoucos elementos para ordenar.");
        return;
    }
    for (int i = 1; i< qtd; i++) {
        Animal atual = listAnimals[i];
        int j = i - 1;

        while (j >= 0 && strcmp(listAnimals[j].nome,atual.nome) > 0) {
            listAnimals[j+1] = listAnimals[j];
            j--;
        }
        listAnimals[j+1] = atual;
    }
    printf("\nOrdenado com Insertion Sort.");
}