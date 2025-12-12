#include <stdio.h>
#include "globals.h"
void Desempilhar (){
    if (qtdP>0){
    qtdP--;
    }
    else {
        printf("não há animais para desempilhar");
    }
}