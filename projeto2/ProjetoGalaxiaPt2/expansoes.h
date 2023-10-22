#ifndef EXPANSOES_H
#define EXPANSOES_H

#include "config.h"
#include "heap.h"

// Defina uma estrutura de nave vazia
Nave criarNaveVazia();

// Função para verificar se ocorreu uma expansão da passagem
int verificaExpansao(Prio* fp, RecursosExpansao recursosExpansao);

//funcao para comparar os recursos da nave
int compararRecursos(Prio* fp, RecursosExpansao);

//cria uma nave de testes
Nave criarNaveTeste();

//funcao para imprimir nomes de recursos da expansao
void imprimirNomesRecursos(const RecursosExpansao *recursos);

#endif // EXPANSOES_H
