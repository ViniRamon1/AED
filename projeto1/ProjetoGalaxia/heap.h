#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct passageiros {
    int id;
    int idade;
    char planetaOrigem[100];
    char nome[100];
} Passageiros;

typedef struct recurso {
    char nome[100];
    int quantidade;
} Recurso;

typedef struct prioridade {
    int nave_tamanho;
    Passageiros passageiros[100];
    Recurso recursos[100];
} Prio;

typedef struct espaconave {
    int prioridade;
    int tam_passageiro;
    int tam_recursos_transportados;
    Passageiros passageiros[100];
    Recurso recursos_transportados[100];
} Nave;

Prio* create_heap();
void libera(Prio* fp);
int tamanho(Prio* fp);
int cheia(Prio* fp);
int vazia(Prio* fp);
void inserir_nave(Prio* fp, Nave nave);
void remover_nave(Prio* heap);
void imprimir_naves(Prio* heap);

#endif // HEAP_H_INCLUDED
