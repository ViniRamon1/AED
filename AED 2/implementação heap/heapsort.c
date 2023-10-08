#include <stdio.h>
#include <stdlib.h>

long long compHs;

void troca(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}

void geraVet(int v[], int n){
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	   v[i]=rand()%500;
}

void printVetor(int v[],int n){
	int i;
	for(i=0;i<n;i++)
	  printf("%d |",v[i]);
	printf("\n");  
}

void criaHeap(int v[], int n, int i){
    int pai = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
  
    if (esquerda < n && v[esquerda] > v[pai]){
    	pai = esquerda;
        compHs++;
	}
      
    if (direita < n && v[direita] > v[pai]){
      pai = direita;
      compHs++;
  }
    if (pai != i) {
      troca(&v[i], &v[pai]);
      compHs++;
      criaHeap(v, n, pai);
    }
}
  
void hsort(int v[], int n) {
  	
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      criaHeap(v, n, i);
  
    for (i = n - 1; i >= 0; i--) {
      troca(&v[0], &v[i]);
  
      criaHeap(v, i, 0);
    }
}

int main(){
	int *vet, n;
	printf("Tamanho do vetor:");
	scanf("%d",&n);
	vet = malloc(sizeof(int)*n);
	geraVet(vet,n);
	printVetor(vet,n);
	hsort(vet,n);
	printf("Vetor ordenado:\n");
    printVetor(vet,n);  
	return 0;
}