#include <stdio.h>
#include "expansoes.h"

// Função para criar uma nave vazia
Nave criarNaveVazia() {
    Nave naveVazia;
    naveVazia.prioridade = 0;
    // Inicialize outros campos conforme necessário
    return naveVazia;
}

// Função para verificar se ocorreu uma expansão da passagem
Nave verificaExpansao(Prio* fp, int ultimaExpansao, Recurso recursosExpansao) {
    Nave naveExpansao = criarNaveVazia(); // Inicialize uma nave vazia

    Nave naveAtual;
    int tamanhoFila = tamanho(fp);
    int expansaoEncontrada = 0;

    for (int i = ultimaExpansao + 1; i < tamanhoFila; i++) {
        naveAtual = recuperar(fp, i);

        if (compararRecursos(naveAtual.recursos_transportados, recursosExpansao)) {
            naveExpansao = naveAtual; // Ocorrência de expansão encontrada
            expansaoEncontrada = 1;
            break;
        }
    }

    if (!expansaoEncontrada) {
        // Lógica adicional se nenhuma expansão for encontrada
    }

    return naveExpansao;
}

// Função para comparar recursos transportados pela nave com os recursos da expansão
int compararRecursos(RecursosNave recursosNave, Recurso recursosExpansao) {
    // Implemente a lógica para verificar se os recursos da nave coincidem com os da expansão
    // Certifique-se de considerar todas as permutações possíveis
    // Retorne 1 se uma correspondência for encontrada, 0 caso contrário
}
