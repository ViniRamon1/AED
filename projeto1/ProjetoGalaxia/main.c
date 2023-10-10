#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

Nave obter_nave(){

}
int main() {
    srand((unsigned)time(NULL));
    int option = 0;

    Prio* heap = criar_heap();

    printf("Bem-vindo ao sistema de controle de naves!\n");

    do {
        menu();
        printf("\nSelecione o que deseja: ");
        printf("\n\t***********Menu***************");
        printf("\n1 - adicionar uma nave\n[2] - retirar nave\n[3] - visualizar naves\n[4] - Sair\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                inserir_nave(heap);
                printf("\nInserção Realizada\n");
                break;
            case 2:
                remover_nave(heap, obter_nave());
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
