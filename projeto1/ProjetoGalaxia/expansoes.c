#include <stdio.h>
#include "expansoes.h"

// Fun��o para criar uma nave vazia
Nave criarNaveVazia() {
    Nave naveVazia;
    naveVazia.prioridade = 0;
    // Inicialize outros campos conforme necess�rio
    return naveVazia;
}

// Fun��o para verificar se ocorreu uma expans�o da passagem
Nave verificaExpansao(Prio* fp, int ultimaExpansao, Recurso recursosExpansao) {
    Nave naveExpansao = criarNaveVazia(); // Inicialize uma nave vazia

    Nave naveAtual;
    int tamanhoFila = tamanho(fp);
    int expansaoEncontrada = 0;

    for (int i = ultimaExpansao + 1; i < tamanhoFila; i++) {
        naveAtual = recuperar(fp, i);

        if (compararRecursos(naveAtual.recursos_transportados, recursosExpansao)) {
            naveExpansao = naveAtual; // Ocorr�ncia de expans�o encontrada
            expansaoEncontrada = 1;
            break;
        }
    }

    if (!expansaoEncontrada) {
        // L�gica adicional se nenhuma expans�o for encontrada
    }

    return naveExpansao;
}

// Fun��o para comparar recursos transportados pela nave com os recursos da expans�o
int compararRecursos(RecursosNave recursosNave, Recurso recursosExpansao) {
    // Implemente a l�gica para verificar se os recursos da nave coincidem com os da expans�o
    // Certifique-se de considerar todas as permuta��es poss�veis
    // Retorne 1 se uma correspond�ncia for encontrada, 0 caso contr�rio
}
