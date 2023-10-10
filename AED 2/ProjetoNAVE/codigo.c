#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de Passageiro
struct Passenger {
    char name[50];
    int age;
    char originPlanet[50];
    int uniqueID;
};

// Estrutura de Espaçonave
struct Spacecraft {
    int priority;
    struct Passenger passengers[10]; // Máximo de 10 passageiros
    int passengerCount;
    char resources[10][50]; // Máximo de 10 recursos
    int resourceCount;
};

// Função auxiliar para gerar um número aleatório entre min e max
int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {

    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    // Criação da fila de prioridades
    struct Spacecraft priorityQueue[100]; // Máximo de 100 espaçonaves
    int queueSize = 0;

    // Interface de usuário
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Adicionar espaconave\n");
        printf("2. Exibir fila de prioridades\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Adicionar espaçonave
                if (queueSize < 100) {
                    struct Spacecraft newSpacecraft;
                    printf("Informe a prioridade da espaconave: ");
                    scanf("%d", &newSpacecraft.priority);

                    // Verifique se a prioridade deve ser alterada com 10% de probabilidade
                    if (generateRandomNumber(1, 10) == 1) {
                        newSpacecraft.priority = generateRandomNumber(1, 100); // Gere uma nova prioridade aleatória
                    }

                    printf("Quantos passageiros a espaconave possui? ");
                    scanf("%d", &newSpacecraft.passengerCount);

                    for (int i = 0; i < newSpacecraft.passengerCount; i++) {
                        printf("Passageiro %d:\n", i + 1);
                        printf("Nome: ");
                        scanf("%s", newSpacecraft.passengers[i].name);
                        printf("Idade: ");
                        scanf("%d", &newSpacecraft.passengers[i].age);
                        printf("Planeta de origem: ");
                        scanf("%s", newSpacecraft.passengers[i].originPlanet);
                        newSpacecraft.passengers[i].uniqueID = rand(); // Gere um ID único simples
                    }

                    printf("Quantos recursos a espaconave transporta? ");
                    scanf("%d", &newSpacecraft.resourceCount);

                    for (int i = 0; i < newSpacecraft.resourceCount; i++) {
                        printf("Recurso %d: ", i + 1);
                        scanf("%s", newSpacecraft.resources[i]);
                    }

                    // Insira a espaçonave na fila
                    priorityQueue[queueSize] = newSpacecraft;
                    queueSize++;
                } else {
                    printf("A fila de prioridades esta cheia.\n");
                }
                break;

            case 2:
                // Exibir fila de prioridades
                printf("Fila de Prioridades:\n");
                for (int i = 0; i < queueSize; i++) {
                    printf("Espaconave %d - Prioridade: %d\n", i + 1, priorityQueue[i].priority);
                }
                break;

            case 3:
                // Sair
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
