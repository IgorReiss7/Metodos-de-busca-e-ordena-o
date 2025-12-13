#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char especie[50];
    int idade;
} Animal;

#define MAX 10
Animal listAnimals[MAX];
int qtd = 0;

#define TAM_HASH 19
Animal hashTable[TAM_HASH];
int ocupado[TAM_HASH]; 

int hashNome(char *nome) {
    int h = 0;
    while (*nome) {
        h = (h * 31 + *nome) % TAM_HASH;
        nome++;
    }
    return h;
}

void construirHash() {
    for (int i = 0; i < TAM_HASH; i++)
        ocupado[i] = 0;

    for (int i = 0; i < qtd; i++) {
        int pos = hashNome(listAnimals[i].nome);

        while (ocupado[pos]) {
            pos = (pos + 1) % TAM_HASH;
        }

        hashTable[pos] = listAnimals[i];
        ocupado[pos] = 1;
    }
}

void insert() {
    if (qtd >= MAX) {
        printf("Lista cheia\n");
        return;
    }

    printf("Nome do animal: ");
    scanf(" %49[^\n]", listAnimals[qtd].nome);

    printf("Especie: ");
    scanf(" %49[^\n]", listAnimals[qtd].especie);

    printf("Idade do animal: ");
    scanf("%d", &listAnimals[qtd].idade);

    qtd++;
    printf("Animal cadastrado com sucesso!\n");
}

void exclude() {
    if (qtd==0){
        printf("Nenhum animal foi cadastrado ainda");
        return; 
    }
    char nomeBuscar[50];
    printf("Digite o nome do animal que deseja excluir: ");
    scanf(" %49[^\n]", nomeBuscar);
    int index = -1;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(listAnimals[i].nome, nomeBuscar) ==0) { 
            index = i; 
            break;
        }
    }
    if (index == -1) {
        printf("\nAnimal não encontrado.");
        return;
    }
        for (int i = index; i < qtd-1; i++) { 
        listAnimals[i]=listAnimals[i + 1];
        }
        qtd--;
        printf("Animal foi excluido com sucesso!");
    
}

void display() { 
    if (qtd == 0){ 
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    printf("\n<== Lista de Animais ==>\n");
    for (int i = 0; i < qtd; i++) {
        printf("\n Animal %d\n",i+1); 
        printf("Nome: %s\n", listAnimals[i].nome);
        printf("Espécie: %s\n", listAnimals[i].especie);
        printf("Idade: %d\n", listAnimals[i].idade);
    }
}

void LinearSearch() {
    if (qtd == 0) {
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    char buscarNome[50];
    printf("Digite o nome do animal que deseja buscar: ");
    scanf(" %49[^\n]",buscarNome); 
    int encontrado = -1;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(listAnimals[i].nome, buscarNome) == 0) {
            encontrado = i;
            break;
        }
}
    if (encontrado == -1) {
        printf("Animal não encontrado :( \n");
    } else {
        printf("\nAnimal encontrado!\n");
        printf("Nome: %s\n", listAnimals[encontrado].nome);
        printf("Espécie: %s\n", listAnimals[encontrado].especie);
        printf("Idade: %d\n", listAnimals[encontrado].idade);
    }
}

void BinarySearch() {
    if (qtd == 0) {
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }
    char buscarNome[50];
    printf("Digite o nome do animal que deseja buscar: ");
    scanf(" %49[^\n]",buscarNome); 
    int inicio = 0;
    int fim = qtd-1;
    while (inicio<=fim)
    {   
        int meio = (inicio+fim)/2;
        int comparacao = strcmp(listAnimals[meio].nome, buscarNome);
        if (comparacao==0){
            printf("o animal com o nome buscado esta no indice %d", meio);
            return;
        }
        else if (comparacao>0){
            fim = meio - 1;
        }
        else if (comparacao<0){
            inicio = meio + 1;
        }
    }
    printf("animal não encontrado\n");
}

void HashSearch() {
    if (qtd == 0) {
        printf("Nenhum animal foi cadastrado.\n");
        return;
    }

    construirHash(); 

    char buscarNome[50];
    printf("Digite o nome do animal que deseja buscar: ");
    scanf(" %49[^\n]", buscarNome);

    int pos = hashNome(buscarNome);
    int inicio = pos;

    while (ocupado[pos]) {
        if (strcmp(hashTable[pos].nome, buscarNome) == 0) {
            printf("\nAnimal encontrado (Hash)!\n");
            printf("Nome: %s\n", hashTable[pos].nome);
            printf("Espécie: %s\n", hashTable[pos].especie);
            printf("Idade: %d\n", hashTable[pos].idade);
            return;
        }

        pos = (pos + 1) % TAM_HASH;

        if (pos == inicio)
            break; 
    }

    printf("Animal não encontrado (Hash).\n");
}

void BubbleSort() {
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
    display();
    printf("\n Ordenado por método bubble sort");
}

void SelectionSort() {
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

void InsertionSort() {
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
    display();
    printf("\nOrdenado com Insertion Sort.");
}

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
        limparBuffer(); 
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
            printf("1 - BuscaLinear\n");
            printf("2 - BuscaBinária\n");
            printf("3 - \n");
            printf("Escolha o método: ");
            
            scanf("%d", &opcBusca);
            limparBuffer();

            switch (opcBusca) {
                case 1: LinearSearch(); break;
                case 2: BinarySearch(); break;     
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
                case 1: BubbleSort(); break;
                case 2: SelectionSort(); break;
                case 3: InsertionSort(); break;
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
