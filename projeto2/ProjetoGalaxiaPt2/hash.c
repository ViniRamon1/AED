#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "config.h"
#include "hash.h"

HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            ht->tabela[i] = NULL;
        }
    }
    return ht;
}

void destroyHashTable(HashTable* ht) {
    if (ht == NULL) {
        return;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = ht->tabela[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(ht);
}

int calcularHash(char recursos[3][100]) {
    // Função de hash simples para calcular o índice da tabela
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; recursos[i][j] != '\0'; j++) {
            hash = (hash * 31 + recursos[i][j]) % HASH_SIZE;
        }
    }
    return hash;
}

void atualizarTabela(HashTable* ht, Nave nave) {
    int hash = calcularHash(nave.recursos_transportados);
    HashNode* node = ht->tabela[hash];

    char recursos[3][100];
    // Copie os recursos para a variável
    strcpy(recursos[0], nave.recursos_transportados[0].nome);
    strcpy(recursos[1], nave.recursos_transportados[1].nome);
    strcpy(recursos[2], nave.recursos_transportados[2].nome);

    while (node != NULL) {
        if (strcmp(node->recursos[0], recursos[0]) == 0 &&
            strcmp(node->recursos[1], recursos[1]) == 0 &&
            strcmp(node->recursos[2], recursos[2]) == 0) {
            // Os recursos são iguais, retorne sem adicionar
            return;
        }
        node = node->next;
    }

    // Permutação não encontrada, criando uma nova entrada
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->recursos[0], recursos[0]);
    strcpy(newNode->recursos[1], recursos[1]);
    strcpy(newNode->recursos[2], recursos[2]);
    newNode->combinacoes_distintas = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && j != k && i != k) {
                    // Verifique se as combinações são distintas
                    if (strcmp(newNode->recursos[i], newNode->recursos[j]) == 0 &&
                        strcmp(newNode->recursos[i], newNode->recursos[k]) == 0 &&
                        strcmp(newNode->recursos[j], newNode->recursos[k]) == 0) {
                        newNode->combinacoes_distintas++;
                        //printf("%d", newNode->combinacoes_distintas);
                    }
                }
            }
        }
    }
    if (newNode->combinacoes_distintas == 6) {
        // Se houver 6 combinações distintas, registre a expansão
        printf("Expansao registrada para recursos: %s, %s, %s\n", newNode->recursos[0], newNode->recursos[1], newNode->recursos[2]);
    }
    newNode->next = ht->tabela[hash];
    ht->tabela[hash] = newNode;
}

int verificarExpansao(HashTable* ht, Nave nave) {
    // Calcula o hash dos recursos transportados pela nave
    int hash = calcularHash(nave.recursos_transportados);

    // Procura o nó correspondente na tabela hash
    HashNode* node = ht->tabela[hash];

    char recursos[3][100];
    // Copia os recursos da nave para a variável
    strcpy(recursos[0], nave.recursos_transportados[0].nome);
    strcpy(recursos[1], nave.recursos_transportados[1].nome);
    strcpy(recursos[2], nave.recursos_transportados[2].nome);

    // Percorre a lista encadeada na posição do hash
    while (node != NULL) {
        if (strcmp(node->recursos[0], recursos[0]) == 0 &&
            strcmp(node->recursos[1], recursos[1]) == 0 &&
            strcmp(node->recursos[2], recursos[2]) == 0) {
            // Recursos iguais, verifique se possui 6 combinações distintas
            if (node->combinacoes_distintas == 6) {
                return 1; // Expansão disponível
            } else {
                return 0; // Expansão não disponível
            }
        }
        node = node->next;
    }

    return 0; // Nenhum nó encontrado, portanto, nenhuma expansão disponível
}


void imprimirTabela(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = ht->tabela[i];
        while (node != NULL) {
            printf("Hash %d - Recursos: %s, %s, %s, Contagem: %d\n", i, node->recursos[0], node->recursos[1], node->recursos[2], node->combinacoes_distintas);
            node = node->next;
        }
    }
}

void permutarRecursos(Recurso recursos[3], int i, int j) {
    Recurso temp = recursos[i];
    recursos[i] = recursos[j];
    recursos[j] = temp;
}

