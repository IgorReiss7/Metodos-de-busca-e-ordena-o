#include <string.h>
#include <stdio.h>
#include "Animal.h"
#include "globals.h"
#include "Display.h"
void ordering2() {
    if (qtd < 2) {
    printf("\nPoucos elementos para ordenar.");
    return;
    }
    for (int i = 0; i < qtd - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(listAnimals[j].nome,listAnimals[menor].nome) < 0) {
            menor = j;
        }
        }
        if (menor != i) {
            Animal temp =listAnimals[i];
            listAnimals[i] =listAnimals[menor];
            listAnimals[menor]= temp;
        }
    }
    display();
    printf("\nOrdenado com Selection Sort.");
}
