#include <string.h>
#include <stdio.h>
#include "Animal.h"
#include "globals.h"

void ordering1() {
    if (qtd < 2) {
        printf("\nPoucos elementos para ordenar.");
        return;
    }

    for (int i =0; i < qtd -1; i++) {
        for (int j = 0; j < qtd - 1 - i; j++) {
            if (strcmp(listAnimals[j].nome, listAnimals[j +1].nome) > 0) {
            Animal temp = listAnimals[j];
            listAnimals[j] = listAnimals[j + 1];
            listAnimals[j + 1] = temp;
        }
    }
}
    printf("\n Ordenado por método bubble sort");
}