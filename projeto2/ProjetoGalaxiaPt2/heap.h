#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "config.h"

typedef struct Passageiros {
    int id;
    int idade;
    char planetaOrigem[100];
    char nome[100];
} Passageiros;

typedef struct Recurso {
    char nome[100];
    int quantidade; //nesta parte nao importa a quantidade
} Recurso;

typedef struct Nave {
    int prioridade;
    int tam_passageiro;
    int tam_recursos_transportados;
    Passageiros passageiros[100];
    Recurso recursos_transportados[4]; //4 compartimentos
} Nave;

typedef struct Prio {
    int nave_tamanho;
    Nave naves[100];
} Prio;

void subir(Prio* fp, int filho);
void descer(Prio* fp, int pai);
Prio* create_heap();
void libera(Prio* fp);
int tamanho(Prio* fp);
int cheia(Prio* fp);
int vazia(Prio* fp);
void inserir_nave(Prio* fp, Nave nave);
void remover_nave(Prio* fp);
void imprimir_naves(Prio* fp);
int generateRandomNumber(int min, int max);
void clearScreen();
Nave recuperar(Prio* fp, int indice);
void imprimirDetalhesNave(Nave nave);

#endif // HEAP_H_INCLUDED
