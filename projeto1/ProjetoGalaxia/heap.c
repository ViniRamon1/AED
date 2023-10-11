#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nave {
    int prioridade;
    // Outros campos da Nave
} Nave;

typedef struct Prio {
    int nave_tamanho;
    Nave naves[100];
    // Outros campos da fila de prioridade
} Prio;

Prio* create_heap() {
    Prio* fp = (Prio*)malloc(sizeof(Prio));
    if (fp != NULL) {
        fp->nave_tamanho = 0;
    }
    return fp;
}

void libera(Prio* fp) {
    free(fp);
}

int cheia(Prio* fp) {
    if (fp == NULL) {
        return -1;
    } else if (fp->nave_tamanho == 100) {
        return 1;
    } else {
        return 0;
    }
}

int vazia(Prio* fp) {
    if (fp == NULL) {
        return -1;
    } else if (fp->nave_tamanho == 0) {
        return 1;
    } else {
        return 0;
    }
}

int tamanho(Prio* fp) {
    if (fp == NULL) {
        return -1;
    } else {
        return fp->nave_tamanho;
    }
}

void inserir_nave(Prio* fp, Nave nave) {
    if (fp == NULL || cheia(fp)) {
        return;
    }
    fp->naves[fp->nave_tamanho] = nave;
    subir(fp, fp->nave_tamanho);
    fp->nave_tamanho++;
}

void remover_nave(Prio* fp) {
    if (fp == NULL || vazia(fp)) {
        return;
    }
    fp->nave_tamanho--;
    fp->naves[0] = fp->naves[fp->nave_tamanho];
    descer(fp, 0);
}

void imprimir_naves(Prio* fp) {
    printf("\nNaves na fila de prioridade:\n");
    for (int i = 0; i < fp->nave_tamanho; i++) {
        printf("Nave %d - Prioridade: %d\n", i + 1, fp->naves[i].prioridade);
    }
}

void subir(Prio* fp, int filho) {
    int pai_idx;
    Nave temp;
    pai_idx = (filho - 1) / 2;
    while (filho > 0 && fp->naves[pai_idx].prioridade < fp->naves[filho].prioridade) {
        temp = fp->naves[filho];
        fp->naves[filho] = fp->naves[pai_idx];
        fp->naves[pai_idx] = temp;
        filho = pai_idx;
        pai_idx = (pai_idx - 1) / 2;
    }
}

void descer(Prio* fp, int pai_idx) {
    Nave temp;
    int filho = 2 * pai_idx + 1;
    while (filho < fp->nave_tamanho) {
        if (filho < fp->nave_tamanho - 1 && fp->naves[filho].prioridade < fp->naves[filho + 1].prioridade) {
            filho++;
        }
        if (fp->naves[pai_idx].prioridade >= fp->naves[filho].prioridade) {
            break;
        }
        temp = fp->naves[pai_idx];
        fp->naves[pai_idx] = fp->naves[filho];
        fp->naves[filho] = temp;
        pai_idx = filho;
        filho = 2 * pai_idx + 1;
    }
}
