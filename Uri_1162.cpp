#include <stdio.h>
#include <stdlib.h>


int ordenarContar (int *vetor, int tamanho){
	int cont, aux, i, trocas = 0;
	for (cont = 1; cont < tamanho; cont++) {
   		for (i = 0; i < tamanho - 1; i++) {
     		if (vetor[i] > vetor[i + 1]) {
       			aux = vetor[i];
       			vetor[i] = vetor[i + 1];
       			vetor[i + 1] = aux;
       			trocas = trocas + 1;
     		}
   		}
 	}
 	return trocas;
}

int main(){
	int quantCasos, quantVagoes, quantTrocas, i,cont = 0;
	scanf("%d",&quantCasos);
	while(cont < quantCasos){
		scanf("%d",&quantVagoes);
		int *vagoes = (int*)malloc(quantVagoes * sizeof(int));
		
		for (i = 0; i < quantVagoes; i++){
			scanf("%d",&vagoes[i]);
		}
		quantTrocas = ordenarContar(vagoes,quantVagoes);
		printf("Optimal train swapping takes %d swaps.\n",quantTrocas);

		cont++;
	}
	return 0;
}