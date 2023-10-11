#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct Passageiros {
    int id;
    int idade;
    char planetaOrigem[100];
    char nome[100];
} Passageiros;

typedef struct Recurso {
    char nome[100];
    int quantidade;
} Recurso;

typedef struct Nave {
    int prioridade;
    int tam_passageiro;
    int tam_recursos_transportados;
    Passageiros passageiros[100];
    Recurso recursos_transportados[100];
} Nave;

typedef struct Prio {
    int nave_tamanho;
    Nave naves[100];
} Prio;

Prio* create_heap();
void libera(Prio* fp);
int tamanho(Prio* fp);
int cheia(Prio* fp);
int vazia(Prio* fp);
void inserir_nave(Prio* fp, Nave nave);
void remover_nave(Prio* fp);
void imprimir_naves(Prio* fp);
int generateRandomNumber(int min, int max);

#endif // HEAP_H_INCLUDED
