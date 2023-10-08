#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct heap Heap;

Heap* cria_Heap();
void libera_Heap(Heap* fp);
int consulta_Heap(Heap* fp, char* nome);
int insere_Heap(Heap* fp, char *nome, int  prioridade);
int remove_Heap(Heap* fp);
int tamanho_Heap(Heap* fp);
int estaCheia_Heap(Heap* fp);
int estaVazia_Heap(Heap* fp);
void imprime_Heap(Heap* fp);
void heapSort(Heap*, int N);

struct paciente{
    char nome[30];
    int prio;
};

struct heap{
    int qtd;
    struct paciente dados[MAX];
};

int main(){
    struct paciente itens[6] = {{"Carlos",8},
                                {"Vinicius",5},
                                {"Alexandre",4},
                                {"Murillo",2},
                                {"Inacio",6},
                                {"Dudu",3}};

    Heap* fp;
    fp = cria_Heap();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insere_Heap(fp, itens[i].nome,itens[i].prio);
    }

    printf("========Exibindo Lista=============\n");
    imprime_Heap(fp);

    //teste
    printf("========Adicionando Teste(9)=======\n");
    insere_Heap(fp, "Teste",9);
    imprime_Heap(fp);

    printf("========Removendo Maior priori=====\n");
    remove_Heap(fp);
    imprime_Heap(fp);

    printf("========Busca e Remocao de 1 a 6===\n");
    for (i=0; i< 6; i++){
        char nome[30];
        consulta_Heap(fp, nome);
        printf("%d) %s\n",i,nome);
        remove_Heap(fp);
    }

    printf("========Exibindo Lista=============\n");
    imprime_Heap(fp);
    
    //libera_Heap(fp); 
    return 0;
}

Heap* cria_Heap(){
    Heap *fp;
    fp = (Heap*) malloc(sizeof(struct heap));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_Heap(Heap* fp){
    free(fp);
}

int consulta_Heap(Heap* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome,fp->dados[0].nome);
    return 1;
}

void promoverElemento(Heap* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho - 1) / 2;
    while((filho > 0) && (fp->dados[pai].prio <= fp->dados[filho].prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    }
}

int insere_Heap(Heap* fp, char *nome, int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;
    /* insere na primeira posição livre */
    strcpy(fp->dados[fp->qtd].nome,nome);
    fp->dados[fp->qtd].prio = prioridade;
    /* desloca elemento para posição correta */
    promoverElemento(fp,fp->qtd);
    /* incrementa número de elementos no heap */
    fp->qtd++;
    return 1;
}

void rebaixarElemento(Heap* fp, int pai){
    struct paciente temp;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){

        if(filho < fp->qtd-1) /* verifica se tem 2 filhos */
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++; /*filho aponta para filho menor */

        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break; /* encontrou lugar */

        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;

        pai = filho;
        filho = 2 * pai + 1;
    }
}

int remove_Heap(Heap* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;

    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixarElemento(fp,0);
    return 1;
}

int tamanho_Heap(Heap* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_Heap(Heap* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}

int estaVazia_Heap(Heap* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}

void imprime_Heap(Heap* fp){
    if(tamanho_Heap(fp) == 0){
        printf("Lista Vazia");
        return 0;
    if(fp == NULL)
        return -1;
    }
    int i;
    for(i=0; i < fp->qtd ; i++){
        printf("%d) Prio: %d \tNome: %s\n",i,fp->dados[i].prio,fp->dados[i].nome);
    }
}