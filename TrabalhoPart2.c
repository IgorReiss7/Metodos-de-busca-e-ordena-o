#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[50];
    char especie[50];
    int idade;
} Animal;

#define MAX 10
Animal filaAnimais[MAX];
Animal pilhaAnimais[MAX];
int qtdF = 0;
int qtdP = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Enfileirar () {
    if (qtdF>= MAX){
        printf("Lista cheia"); 
        return;
    }

    printf("Nome do animal: ");
    scanf(" %49[^\n]", filaAnimais[qtdF].nome);

    printf("Especie: ");
    scanf(" %49[^\n]", filaAnimais[qtdF].especie);

    printf("idade do animal: ");
    scanf("%d", &filaAnimais[qtdF].idade); 
   
    qtdF++;
    printf("Animal cadastrado com sucesso!\n");
}

void Empilhar () {
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
    printf("Animal cadastrado com sucesso!\n");
}

void ExibirFila() { 
    if (qtdF == 0){ 
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<== Fila de animais ==>\n");
    for (int i = 0; i < qtdF; i++) { 
        printf("\n Animal %d\n",i+1);
        printf("Nome: %s\n", filaAnimais[i].nome);
        printf("Espécie: %s\n", filaAnimais[i].especie);
        printf("Idade: %d\n", filaAnimais[i].idade);
    }
}

void ExibirPilha() { 
    if (qtdP == 0){ 
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<==Pilha de Animais ==>\n");
    for (int i = 0; i < qtdP; i++) { 
        printf("\n Animal %d\n",i+1);
        printf("Nome: %s\n", pilhaAnimais[i].nome);
        printf("Espécie: %s\n", pilhaAnimais[i].especie);
        printf("Idade: %d\n", pilhaAnimais[i].idade);
    }
}

void Desempilhar (){
    if (qtdP>0){
    qtdP--;
    }
    else {
        printf("não há animais para desempilhar");
    }
}

void Desenfileirar(){
    if (qtdF>0){
        if (qtdP<MAX){
        pilhaAnimais[qtdP]=filaAnimais[0];
        qtdP++;
        }
        else{
            printf("não é possivel desenfileirar pois a pilha já está cheia");
        }
        for(int i=0; i<qtdF-1; i++){
            strcpy (filaAnimais[i].nome, filaAnimais[i+1].nome);
            strcpy (filaAnimais[i].especie, filaAnimais[i+1].especie);
            filaAnimais[i].idade = filaAnimais[i+1].idade;
        }
        qtdF--;
    } else{
        printf("não há mais animais para serem excluidos");
    }
}

int main() {

    int options;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1 - Enfileirar\n");
        printf("2 - Empilhar\n");
        printf("3 - Exibir Fila\n");
        printf("4 - Exibir Pilha\n");
        printf("5 - Desenfileirar\n");
        printf("6 - Desempilhar\n");
        printf("7 - Sair\n");
        printf("============================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &options);
        limparBuffer(); 
        switch (options) {

        case 1:
            Enfileirar();
            break;

        case 2:
            Empilhar();
            break;

        case 3:
            ExibirFila();
            break;

        case 4:
            ExibirPilha();
            break;

        case 5:
            Desenfileirar();
            break;

        case 6:
            Desempilhar();
            break;

        case 7:
            printf("saindo\n");
            break;

        default: 
            printf("Opção inválida\n");
        };
    } while (options!=0);
};
