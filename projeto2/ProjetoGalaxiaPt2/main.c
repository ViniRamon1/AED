#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "heap.h"
#include "expansoes.h"
#include "config.h"
#include "hash.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    // Criando o heap para as naves
    Prio* fp = create_heap();

    // Criando a tabela hash
    HashTable* ht = createHashTable();

    // Adicionando 100 naves ao heap com recursos e prioridade aleatórios
    for (int i = 0; i < MAX_NAVES; i++) {
        Nave nave;
        nave.prioridade = gerarPrioridade();

        for (int j = 0; j < NUM_COMPARTIMENTOS; j++) {
            // Gere recursos aleatórios
            int idRecurso = generateRandomNumber(1, MAX_RECURSOS);
            snprintf(nave.recursos_transportados[j].nome, sizeof(nave.recursos_transportados[j].nome), "Recurso%d", idRecurso);
            nave.tam_recursos_transportados = 3;
            nave.recursos_transportados[j].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
        }

        inserir_nave(fp, nave);
        atualizarTabela(ht, nave);
    }

    // imprimindo heap apenas para teste
    //imprimirHeap(fp);

    // imprimindo hash apenas para teste
    //imprimirTabela(ht);

    //condicao de parada para nao ficar em loop infinito
    int countExpansao = 0;

    while (!vazia(fp) && countExpansao < 100) {

        if (vazia(fp)) {
            printf("lista vazia\n");
            return -1;
        }

        Nave naveAtual = fp->naves[0];

        if (verificarExpansao(ht, naveAtual)) {
            //printf("Expansao verificada.\n");
            // A expansão ocorreu, remova algumas naves aleatoriamente
            int navesRemovidas = generateRandomNumber(1, 100);

            // Verifique se o número aleatório não ultrapassa o número de naves na fila
            if (navesRemovidas > fp->nave_tamanho) {
                navesRemovidas = fp->nave_tamanho;
            }

            printf("Expansao ocorrida, %d naves passaram pela passagem.\n", navesRemovidas);

            // Remova as naves
            for (int i = 0; i < navesRemovidas; i++) {
                remover_nave(fp);
            }
        }
        remover_nave(fp); //nave passou pela passagem
        printf("1 nave removida, sem expansao\n"); //apenas para teste
        //printf("nao houve expansao");
        countExpansao++;
    }


    // imprimindo heap apenas para teste
    imprimirHeap(fp);

    // Libera a memória alocada para o heap e a tabela hash
    libera(fp);
    destroyHashTable(ht);

    return 0;
}
