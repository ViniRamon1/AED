#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

int main() {
    srand((unsigned)time(NULL));
    int option = 0;

    Prio* heap = create_heap();

    printf("Bem-vindo ao sistema de controle de naves!\n");

    do {
        printf("\nSelecione o que deseja: ");
        printf("\n\t***********Menu***************");
        printf("\n1 - Adicionar uma nave\n2 - Retirar nave\n3 - Visualizar naves\n4 - Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                Nave minha_nave; // Crie uma instancia de Nave
                // Preencha os campos da nave conforme necessário
                inserir_nave(heap, minha_nave);
                printf("\nInserção Realizada\n");
                break;
            case 2:
                remover_nave(heap);
                printf("\nRemoção Realizada!\n");
                break;
            case 3:
                imprimir_naves(heap);
                break;
            case 4:
                printf("\nSaindo\n");
                break;
            default:
                printf("\nNão há essa opção\n");
                break;
        }
    } while (option != 4);

    libera(heap);

    return 0;
}
