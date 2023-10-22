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
    for (int i = 0; i < 99; i++) {
        Nave nave;
        nave.prioridade = gerarPrioridade();

        for (int j = 0; j < NUM_COMPARTIMENTOS; j++) {
            // Gere recursos aleatórios
            int idRecurso = generateRandomNumber(1, 100);
            snprintf(nave.recursos_transportados[j].nome, sizeof(nave.recursos_transportados[j].nome), "Recurso%d", idRecurso);
            nave.tam_recursos_transportados = 3;
            nave.recursos_transportados[j].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
        }

        inserir_nave(fp, nave);
    }

    //recuros necessarios para expandir a passagem
    RecursosExpansao recursosExpansao;
    strcpy(recursosExpansao.compartimento[0].nome, "Recurso1");
    strcpy(recursosExpansao.compartimento[1].nome, "Recurso2");
    strcpy(recursosExpansao.compartimento[2].nome, "Recurso3");
    strcpy(recursosExpansao.compartimento[3].nome, "Recurso4");

    //imprimirNomesRecursos(&recursosExpansao);

    //criando nave de teste com os recursos necessarios para haver expansao
    Nave naveTeste = criarNaveTeste();
    inserir_nave(fp, naveTeste);

    //imprime na tela as informações das naves
    for(int i = 0; i < fp->nave_tamanho; i++){
        printf("nave %d: \n", i + 1);
        imprimirDetalhesNave(fp->naves[i]);
        printf("\n");
    }

    int countExpansao = 0; //variavel para determinar o fim do loop
    // Simule as expansões de acordo com as especificações
    while (!vazia(fp) && countExpansao < 100) {

        if (vazia(fp)) {
            printf("lista vazia");
            return -1;
        }

        if (verificaExpansao(fp, recursosExpansao)) {
            // A expansão ocorreu, remova algumas naves aleatoriamente
            int navesRemovidas = generateRandomNumber(1, 100);

            //verifica se o numero aleatorio passa do numero de naves na fila
            if(navesRemovidas > fp->nave_tamanho){
                navesRemovidas = fp->nave_tamanho;
            }

            //remove as naves
            for (int i = 0; i < navesRemovidas; i++) {
                remover_nave(fp);
            }
            printf("Expansao ocorrida, %d naves passaram pela passagem \n", navesRemovidas);
        }
        countExpansao++;
        //printf("Nao houve expansao\n");
    }

    //imprime na tela as informações das naves apos expandir a passagem
    for(int i = 0; i < fp->nave_tamanho; i++){
        printf("nave %d: \n", i + 1);
        imprimirDetalhesNave(fp->naves[i]);
        printf("\n");
    }

    // Libere a memória alocada para o heap
    libera(fp);

    return 0;
}
