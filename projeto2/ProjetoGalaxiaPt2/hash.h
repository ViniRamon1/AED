#ifndef HASH_H
#define HASH_H

#include "config.h"
#include "heap.h"

typedef struct {
    char recursos[3][100];
    int combinacoes_distintas;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    HashNode* tabela[HASH_SIZE];
} HashTable;

HashTable* createHashTable();
void destroyHashTable(HashTable* ht);
int calcularHash(char recursos[3][100]);
void atualizarTabela(HashTable* ht, Nave nave);
int verificarExpansao(HashTable* ht, Nave nave);
void permutarRecursos(Recurso recursos[3], int i, int j); //apenas para teste

#endif // HASH_H
