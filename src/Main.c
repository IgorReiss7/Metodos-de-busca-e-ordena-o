#include <stdio.h>
#include "Insert.h"
#include "Display.h"
#include "Exclude.h"
#include "Search.h"
#include "SearchByName.h"
#include "SearchByAge.h"
#include "SearchBySpecies.h"
#include "OrderingBubbleSort.h"
#include "OrderingInsertionSort.h"
#include "OrderingSelectionSort.h"
#include "globals.h"

// Função para limpar buffer após scanf
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    int options;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1 - Inserir Animal\n");
        printf("2 - Exibir Animais\n");
        printf("3 - Excluir Animal\n");
        printf("4 - Buscar\n");
        printf("5 - Ordenar\n");
        printf("0 - Sair\n");
        printf("============================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &options);
        limparBuffer();  // Evita problemas nos próximos scanf de string

        switch (options) {

        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            exclude();
            break;

        case 4: {
            int opcBusca;
            printf("\n--- Métodos de Busca ---\n");
            printf("1 - Buscar por nome\n");
            printf("2 - Buscar por idade\n");
            printf("3 - Buscar por espécie\n");
            printf("Escolha o método: ");
            
            scanf("%d", &opcBusca);
            limparBuffer();

            switch (opcBusca) {
                case 1: searchByName(); break;
                case 2: searchByAge(); break;      // CORRIGIDO
                case 3: searchBySpecies(); break;  // CORRIGIDO
                default: printf("Opção inválida!\n");
            }
            break;
        }

        case 5: {
            int opcOrd;
            printf("\n--- Métodos de Ordenação ---\n");
            printf("1 - BubbleSort\n");
            printf("2 - SelectionSort\n");
            printf("3 - InsertionSort\n");
            printf("Escolha o método: ");

            scanf("%d", &opcOrd);
            limparBuffer();

            switch (opcOrd) {
                case 1: ordering1(); break;
                case 2: ordering2(); break;
                case 3: ordering3(); break;
                default: printf("Opção inválida!\n");
            }
            break;
        }

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (options != 0);

    return 0;
}
