#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expansoes.h"

// Função para criar uma nave vazia
Nave criarNaveVazia() {
    Nave naveVazia;
    naveVazia.prioridade = 0;
    // Inicialize outros campos conforme necessário
    return naveVazia;
}

// Função para verificar se ocorreu uma expansão da passagem
int verificaExpansao(Prio* fp, int ultimaExpansao, Recurso recursosExpansao) {
    Nave naveAtual;
    int tamanhoFila = tamanho(fp);
    int expansaoEncontrada = 0;
    int navesRemovidas = 0;

    for(int i = ultimaExpansao + 1; i < tamanhoFila; i++) {
        naveAtual = recuperar(fp, i);

        if(compararRecursos(naveAtual.recursos_transportados, recursosExpansao)) {
            // Ocorrência de expansão encontrada
            expansaoEncontrada = 1;
            break;
        }
    }

    if(expansaoEncontrada) {
        // Gere um número aleatório entre 1 e 100 para naves removidas
        navesRemovidas = 1 + rand() % 100;
    }
    return navesRemovidas;
}

// Função para comparar recursos transportados pela nave com os recursos da expansão
int compararRecursos(Recurso* recursosNave, Recurso recursosExpansao) {
    int encontrouCorrespondencia = 1;

    //implementar logica para comparar recursos

    return encontrouCorrespondencia;
}



// Função para remover naves do heap quando não há expansão
void removerNavesSemExpansao(Prio* fp) {
    remover_nave(fp); // Remove a nave de maior prioridade (primeira da fila)
}
