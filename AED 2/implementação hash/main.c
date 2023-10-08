#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct no{
	int valor;
	struct no* prox;
};
typedef struct no NO;

struct listaEncadeada{
    struct no* inicio;
    int tam;
};
typedef struct listaEncadeada LISTAENCADEADA;


//METODOS DA LISTA ENCADEADA

void add(int elemento, LISTAENCADEADA* lista){
	NO *novo = malloc (sizeof(NO));
	novo->valor = elemento;
	novo->prox=NULL;
	if(lista->tam == 0){
		lista->inicio=novo;
	}else{
		novo->prox = lista->inicio;
	}
	lista->inicio = novo;
	lista->tam = lista->tam + 1;
}

void removerInicio(LISTAENCADEADA* lista){
    if(lista->tam > 0){
        NO *lixo=lista->inicio;
        if(lista->tam == 1){
            lista->inicio=NULL;
        }else{
            lista->inicio = lista->inicio->prox;
        }
        lista->tam = lista->tam - 1;
        free(lixo);
    }
}

void removerChave(int chave, LISTAENCADEADA* lista){
    if(lista->tam != 0){
        int verificador = 0;
        NO *aux = lista->inicio;
        if(lista->inicio->valor == chave){
            removerInicio(lista);
            printf("Chave removida...\n");
            verificador++;
        }else{
            for (aux = lista->inicio; aux != NULL; aux = aux->prox){
                if(aux->prox->valor == chave){
                    if(aux->prox->prox != NULL){
                        NO *lixo = aux->prox;
                        aux->prox = aux->prox->prox;
                        free(lixo);
                        printf("Chave removida...\n");
                        verificador++;
                        lista->tam = lista->tam - 1;
                        break;
                    }else{
                        NO *lixo1 = aux->prox;
                        aux->prox = NULL;
                        free(lixo1);
                        printf("Chave removida...\n");
                        verificador++;
                        lista->tam = lista->tam - 1;
                        break;
                    }

                }
            }
        }
    }else{
        printf("A chave nao existe... \n");
    }

}

void imprime(LISTAENCADEADA* lista) {
   NO *aux;
   for (aux = lista->inicio; aux != NULL; aux = aux->prox){
    	printf ("%d ", aux->valor);
   }
   printf("\n");
}

void buscarNaHash(int chave, LISTAENCADEADA* lista, int posicaoHash){
    int verificaCHave = 0;
    if(lista->tam==0){
        printf("A chave nao existe...");
    }else{
        NO *aux;
        int contador = 0;
        for (aux = lista->inicio; aux != NULL; aux = aux->prox){
            if(aux->valor == chave){
                printf ("Sua chave esta na posicao: %i da hash e na posicao: %i da lista encadeada", posicaoHash, contador);
                verificaCHave++;
                break;
            }
            contador++;
        }
        if(verificaCHave == 0){
            printf("A chave nao existe...");
        }
    }
}

int retornaPosicaoAdd(int numero, int casaDecimal, int digito){
    int aux = numero;
    int aux1 = casaDecimal;
    int aux2 = digito;
    int retorno = 0;

    while(aux > 0){
        if(aux1 == aux2){
            retorno = aux % 10;
            return retorno;
        }
        aux = aux / 10;
        aux1--;
    }
}


//METODO DA DIVISÃO
int metodoDivisao(int chave, int tamHash){
    return chave % tamHash;
}

//METODO DA MULTIPLICAÇÃO
/*int metodoMultiplicacao(int chave, int tamTabela){
    //int retorno = (int) (tamTabela * (( (int) chave*0.61803) % 1));
    int aux = (int) chave * 0.61803981;
    float aux2 = chave * 0.61803981;
    float result = aux2 - aux;
    int retorno = (int) tamTabela * result;
    return retorno;
}*/

int verificaTamHash(float tamHash){
    float x;
    for(int i=1; i<=20; i++){
        x = pow(10, i);
        if(x == tamHash){
            return 1;
        }
    }
    return -1;
}

int mult(int chave, int tamHash){
    int auxiliar = tamHash;
    int contador = 0;
    while(auxiliar > 0){
        auxiliar = auxiliar/10;
        contador++;
    }
    float verificador = tamHash;
    int isPotencia = verificaTamHash(verificador);
    if(isPotencia == 1){
        contador--;
    }

    //printf("qtd de digitos pra pegar do vetor final: %i \n", contador);

    int auxChave = chave * chave;
    int contador2 = 0;
    while(auxChave > 0){
        auxChave = auxChave/10;
        contador2++;
    }
    //printf("tamanho do vetor: %i \n", contador2);
    int vetorResult[contador2];
    int auxiliar3 = chave*chave;
    int x = 0;
    for(int i=contador2-1; i>=0; i--){
        x = auxiliar3 % 10;
        vetorResult[i] = x;
        auxiliar3 = auxiliar3/10;
    }
    for(int i=0; i<contador2; i++){
        //printf("Posicao %i do vetor: %i \n", i, vetorResult[i]);
    }

    int retorno = chave*chave;
    if(retorno < tamHash){
        return retorno;
    }else{
        int vetor[contador];
        int x = contador;
        int aux = 0;
        int i = contador2/2;
        //printf("Valor original do i: %i \n", i);
        if(contador2 % 2 == 0){
            i--;
        }
        //printf("Valor do i: %i \n", i);
        while(x > 0){
            vetor[aux] = vetorResult[i];
            i++;
            x--;
            aux++;
        }
        printf("\n \n");
        for(int i=0; i<contador; i++){
            printf("%i \n", vetor[i]);
        }
        printf("\n \n");
        if(contador == 1){
            //printf("hahaha: %i \n", vetor[0]);
            return vetor[0];
        }else{
            int result = 0;
            int m = 1;
            for(int i=contador-1; i>=0; i--){
                result = result + (vetor[i] * m);
                //printf("Valor do mult q vai almentando: %i \n", result);
                m = m*10;

            }
            //printf("Add na posicao: %i \n", result);
            return result;
        }
    }
}

int verificaCasaDecimal(int chave, int casaDecimal){
    if(casaDecimal == 1){
        if(chave >=1 && chave <10){
            return 1;
        }else{
            return 2;
        }
    }else if(casaDecimal == 2){
        if(chave >=10 && chave <100){
            return 1;
        }else{
            return 2;
        }
    }else if(casaDecimal == 3){
        if(chave >=100 && chave <1000){
            return 1;
        }else{
            return 2;
        }
    }else if(casaDecimal == 4){
        if(chave >=1000 && chave <10000){
            return 1;
        }else{
            return 2;
        }
    }else if(casaDecimal == 5){
        if(chave >=10000 && chave <100000){
            return 1;
        }else{
            return 2;
        }
    }else{
        if(chave >=100000 && chave <1000000){
            return 1;
        }else{
            return 2;
        }
    }
}

void mainDivisao(){
    int tamHash;
    printf("Digite o tamanho da hash: ");
    scanf("%i", &tamHash);

    LISTAENCADEADA* hash[tamHash];
    for(int i=0; i<tamHash; i++){
        hash[i] = malloc(sizeof(LISTAENCADEADA));
        hash[i]->tam = 0;
    }

    //MAIN DA DIVISAO

    int loop = 0;
    int chave = 0;
    int posicao = 0;
    while(loop != 5){
        printf("Digite o valor a ser armazenado ");
        scanf("%i", &chave);
        posicao = metodoDivisao(chave, tamHash);
        //posicao = metodoDobra(chave);
        //posicao = mult(chave, tamHash);
        add(chave, hash[posicao]);
        printf("\n");
        loop++;
    }

    for(int i=0; i<tamHash; i++){
        if(hash[i]->tam != 0){
            printf("Imprimindo os valores da posicao %i da hash: ", i);
            imprime(hash[i]);
            printf("\n");
        }
    }

    int loop2 = 0;
    int chaveaux = 0;
    int posicao2 = 0;
    while(loop2 != 2){
        printf("Digite a chave que esta procurando ");
        scanf("%i", &chaveaux);
        posicao2 = metodoDivisao(chaveaux, tamHash);
        buscarNaHash(chaveaux, hash[posicao2], posicao2);
        printf("\n");
        loop2++;
    }

    int x = 0;
    int loop3 = 0;
    while(loop3 != 2){
        printf("Digite a chave que quer remover");
        scanf("%i", &x);
        int aux3 = metodoDivisao(x, tamHash);
        removerChave(x, hash[aux3]);
        printf("\n");
        loop3++;
    }


    for(int i=0; i<tamHash; i++){
        if(hash[i]->tam != 0){
            printf("Imprimindo os valores da posicao %i da hash: ", i);
            imprime(hash[i]);
            printf("\n");
        }
    }
}

void mainMultiplicacao(){

    int tamHash;
    printf("Digite o tamanho da hash: ");
    scanf("%i", &tamHash);

    LISTAENCADEADA* hash[tamHash];
    for(int i=0; i<tamHash; i++){
        hash[i] = malloc(sizeof(LISTAENCADEADA));
        hash[i]->tam = 0;
    }

    int loop = 0;
    int chave = 0;
    int posicao = 0;
    while(loop != 5){
        printf("Digite o valor a ser armazenado ");
        scanf("%i", &chave);
        //posicao = metodoDivisao(chave);
        //posicao = metodoDobra(chave);
        posicao = mult(chave, tamHash);
        add(chave, hash[posicao]);
        printf("\n");
        loop++;
    }

    for(int i=0; i<tamHash; i++){
        if(hash[i]->tam != 0){
            printf("Imprimindo os valores da posicao %i da hash: ", i);
            imprime(hash[i]);
            printf("\n");
        }
    }

    int loop2 = 0;
    int chaveaux = 0;
    int posicao2 = 0;
    while(loop2 != 2){
        printf("Digite a chave que esta procurando ");
        scanf("%i", &chaveaux);
        posicao2 = mult(chaveaux, tamHash);
        buscarNaHash(chaveaux, hash[posicao2], posicao2);
        printf("\n");
        loop2++;
    }

    int x = 0;
    int loop3 = 0;
    while(loop3 != 2){
        printf("Digite a chave que quer remover");
        scanf("%i", &x);
        int aux3 = mult(x, tamHash);
        removerChave(x, hash[aux3]);
        printf("\n");
        loop3++;
    }


    for(int i=0; i<tamHash; i++){
        if(hash[i]->tam != 0){
            printf("Imprimindo os valores da posicao %i da hash: ", i);
            imprime(hash[i]);
            printf("\n");
        }
    }
}

void main(){
    mainDivisao();
    //mainMultiplicacao();
}
