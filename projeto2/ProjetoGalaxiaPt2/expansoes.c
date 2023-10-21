#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expansoes.h"

// Fun��o para criar uma nave vazia
Nave criarNaveVazia() {
    Nave naveVazia;
    naveVazia.prioridade = 0;
    // Inicialize outros campos conforme necess�rio
    return naveVazia;
}

// Fun��o para verificar se ocorreu uma expans�o da passagem
int verificaExpansao(Prio* fp, int ultimaExpansao, Recurso recursosExpansao) {
    Nave naveAtual;
    int tamanhoFila = tamanho(fp);
    int expansaoEncontrada = 0;
    int navesRemovidas = 0;

    for(int i = ultimaExpansao + 1; i < tamanhoFila; i++) {
        naveAtual = recuperar(fp, i);

        if(compararRecursos(naveAtual.recursos_transportados, recursosExpansao)) {
            // Ocorr�ncia de expans�o encontrada
            expansaoEncontrada = 1;
            break;
        }
    }

    if(expansaoEncontrada) {
        // Gere um n�mero aleat�rio entre 1 e 100 para naves removidas
        navesRemovidas = 1 + rand() % 100;
    }
    return navesRemovidas;
}

// Fun��o para comparar recursos transportados pela nave com os recursos da expans�o
int compararRecursos(Recurso* recursosNave, Recurso recursosExpansao) {
    int encontrouCorrespondencia = 1;

    //implementar logica para comparar recursos

    return encontrouCorrespondencia;
}



// Fun��o para remover naves do heap quando n�o h� expans�o
void removerNavesSemExpansao(Prio* fp) {
    remover_nave(fp); // Remove a nave de maior prioridade (primeira da fila)
}
