#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "expansoes.h"
#include "config.h"

// Função para criar uma nave vazia
Nave criarNaveVazia() {
    Nave naveVazia;
    naveVazia.prioridade = 0;
    // Inicialize outros campos conforme necessário
    return naveVazia;
}

// Função para verificar se ocorreu uma expansão da passagem
int verificaExpansao(Prio* fp, RecursosExpansao recursosExpansao) {
    int expansaoEncontrada = 0;

    if (compararRecursos(fp, recursosExpansao)) {
        // Ocorrência de expansão encontrada
        expansaoEncontrada = 1;
    }
    return expansaoEncontrada;
}

int compararRecursos(Prio* fp, RecursosExpansao recursosExpansao) {
    // Variável para contar o número de correspondências encontradas
    int correspondencias = 0;
    int tamanhoFila = tamanho(fp);
    Nave naveAtual;

    for (int a = 0; a < tamanhoFila; a++) {
        naveAtual = fp->naves[a];
        // Percorra os compartimentos da nave
        for (int i = 0; i < 4; i++) {
            // Obtenha o nome do recurso no compartimento da nave
            char nomeNave[100];
            strcpy(nomeNave, naveAtual.recursos_transportados[i].nome);

            // Percorra os compartimentos de expansão
            for (int j = 0; j < 4; j++) {
                // Obtenha o nome do recurso no compartimento de expansão
                char nomeExpansao[100];
                strcpy(nomeExpansao, recursosExpansao.compartimento[j].nome);

                // Compare os nomes dos recursos
                if (strcmp(nomeNave, nomeExpansao) == 0) {
                    // Se os nomes forem iguais, há uma correspondência
                    correspondencias++;
                    break; // Saia do loop interno
                }
            }
        }
    }

    // Se o número de correspondências for igual a 4, todos os recursos correspondem
    return (correspondencias == 4) ? 1 : 0;
}

// Função para remover naves do heap quando não há expansão
void removerNavesSemExpansao(Prio* fp) {
    remover_nave(fp); // Remove a nave de maior prioridade (primeira da fila)
}

//nave criada para testar o metodo de expansao
Nave criarNaveTeste() {
    Nave nave;
    nave.prioridade = 100000;
    nave.tam_recursos_transportados = 4;
    strcpy(nave.recursos_transportados[0].nome, "Recurso1");
    nave.recursos_transportados[0].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
    strcpy(nave.recursos_transportados[1].nome, "Recurso2");
    nave.recursos_transportados[1].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
    strcpy(nave.recursos_transportados[2].nome, "Recurso3");
    nave.recursos_transportados[2].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
    strcpy(nave.recursos_transportados[3].nome, "Recurso4");
    nave.recursos_transportados[3].quantidade = generateRandomNumber(1, 100); //quantidade nao importa
    return nave;
}

void imprimirNomesRecursos(const RecursosExpansao *recursos) {

    printf("Recursos de Expansao:\n");
    for (int i = 0; i < 4; i++) {
        printf("Recurso %d: %s\n", i + 1, recursos->compartimento[i].nome);
    }
    printf("\n");
}
