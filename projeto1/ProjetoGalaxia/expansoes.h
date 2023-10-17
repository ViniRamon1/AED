#ifndef EXPANSOES_H
#define EXPANSOES_H

#include "config.h"
#include "heap.h"

// Defina uma estrutura de nave vazia
Nave criarNaveVazia();

// Função para verificar se ocorreu uma expansão da passagem
Nave verificaExpansao(Prio* fp, int ultimaExpansao, Recurso recursosExpansao);

#endif // EXPANSOES_H
