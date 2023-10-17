#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include "heap.h"
#include "expansoes.h"
#include "config.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    srand((unsigned)time(NULL));
    int option = 0;

    Prio* heap = create_heap();
    Nave minhaNave;
    minhaNave.prioridade = generateRandomNumber(1, 100);
    time_t ultimaExpansao = -1;

    printf("Bem-vindo ao sistema de controle de naves!\n");

    do {
        printf("\nSelecione o que deseja: ");
        printf("\n\t***********Menu***************");
        printf("\n1 - Adicionar uma nave\n2 - Retirar nave\n3 - Visualizar naves\n4 - Sair\n5 - Parte 2\n\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                clearScreen();

                Nave minhaNave; // Crie uma instância de Nave

                // Preencha os campos da nave conforme necessário
                printf("Digite a prioridade da nave: ");
                scanf("%d", &minhaNave.prioridade);

                printf("Digite o numero de passageiros a bordo: ");
                scanf("%d", &minhaNave.tam_passageiro);

                // Captura informações dos passageiros
                for (int i = 0; i < minhaNave.tam_passageiro; i++) {
                    printf("Digite o id do passageiro %d: ", i + 1);
                    scanf("%d", &minhaNave.passageiros[i].id);
                    getchar(); // Limpe o caractere de quebra de linha pendente

                    printf("Digite o nome do passageiro %d: ", i + 1);
                    fgets(minhaNave.passageiros[i].nome, sizeof(minhaNave.passageiros[i].nome), stdin);
                    minhaNave.passageiros[i].nome[strcspn(minhaNave.passageiros[i].nome, "\n")] = '\0'; // Remova a quebra de linha, se presente

                    printf("Digite a idade do passageiro %d: ", i + 1);
                    scanf("%d", &minhaNave.passageiros[i].idade);
                    getchar(); // Limpe o caractere de quebra de linha pendente

                    printf("Digite o planeta de origem do passageiro %d: ", i + 1);
                    fgets(minhaNave.passageiros[i].planetaOrigem, sizeof(minhaNave.passageiros[i].planetaOrigem), stdin);
                    minhaNave.passageiros[i].planetaOrigem[strcspn(minhaNave.passageiros[i].planetaOrigem, "\n")] = '\0'; // Remova a quebra de linha, se presente
                }

                printf("Digite o numero de recursos transportados: ");
                scanf("%d", &minhaNave.tam_recursos_transportados);

                // Captura informações dos recursos transportados
                for (int i = 0; i < minhaNave.tam_recursos_transportados; i++) {
                    printf("Digite o nome do recurso %d: ", i + 1);
                    scanf("%s", minhaNave.recursos_transportados[i].nome); // Use fgets para capturar nomes com espaços em branco
                    printf("Digite a quantidade do recurso %d: ", i + 1);
                    scanf("%d", &minhaNave.recursos_transportados[i].quantidade);
                }

                if (generateRandomNumber(1, 10) == 1) { // 10% de probabilidade de mudar a prioridade
                    minhaNave.prioridade = generateRandomNumber(1, 100); // Gere uma nova prioridade aleatória
                }

                inserir_nave(heap, minhaNave);
                clearScreen();
                printf("\nInsercao Realizada\n");
                break;
            case 2:
                remover_nave(heap);
                clearScreen();
                printf("\nRemocao Realizada!\n");
                break;
            case 3:
                clearScreen();
                if(vazia(heap)){
                    printf("\nNao ha naves!\n");
                } else {
                    //imprimir_naves(heap);
                    imprimirDetalhesNave(heap->naves[0]);;
                }
                break;
            case 4:
                clearScreen();
                printf("\nSaindo\n");
                break;
            case 5:
                clearScreen();
                int option2;

                do {
                    printf("\nSelecione o que deseja na Parte 2: ");
                    printf("\n\t***********Menu Parte 2***************");
                    printf("\n1 - Verificar expansao\n2 - Outra funcionalidade\n3 - Voltar para o menu principal\n\n");
                    scanf("%d", &option2);

                    switch (option2) {
                        case 1:
                            // Implemente a funcionalidade de verificar expansão aqui
                            // Use a função verificaExpansao
                            break;
                        case 2:
                            // Implemente outra funcionalidade da parte 2 aqui, se houver
                            break;
                        case 3:
                            clearScreen();
                            break;
                        default:
                            clearScreen();
                            printf("\nNao ha essa opcao na Parte 2\n");
                            break;
                    }
                } while (option2 != 3);
                break;
            default:
                clearScreen();
                printf("\nNao ha essa opcao\n");
                break;
        }
    } while (option != 4);

    libera(heap);

    return 0;
}
