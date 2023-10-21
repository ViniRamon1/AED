#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include "heap.h"
#include "expansoes.h"
#include "config.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    // Criando o heap para as naves
    Prio* fp = create_heap();

    // Adicionando 100 naves ao heap com recursos e prioridade aleatórios
    for (int i = 0; i < 100; i++) {
        Nave nave;
        nave.prioridade = gerarPrioridade();

        for (int j = 0; j < NUM_COMPARTIMENTOS; j++) {
            // Gere recursos aleatórios
            int idRecurso = generateRandomNumber(1, 100);
            snprintf(nave.recursos_transportados[j].nome, sizeof(nave.recursos_transportados[j].nome), "Recurso%d", idRecurso);
            nave.recursos_transportados[j].quantidade = 1;
        }

        inserir_nave(fp, nave);
    }

    imprimir_naves(fp);

    // Libere a memória alocada para o heap
    libera(fp);

    return 0;
}
