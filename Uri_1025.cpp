#include <stdio.h>
#include <stdlib.h>



void ordenar(int *vetorDesordenado, int comecoDoVetor, int fimDoVetor) { //algoritmo quick-sort adaptado de Vinícius de Novais Hipólito do site programasprontos.com
    int i, j, x, y;
    i = comecoDoVetor;
    j = fimDoVetor;
    x = vetorDesordenado[(comecoDoVetor + fimDoVetor) / 2];

    while(i <= j) {
        while(vetorDesordenado[i] < x && i < fimDoVetor){
            i++;
        }
        while(vetorDesordenado[j] > x && j > comecoDoVetor){
            j--;
        }
        if(i <= j){
            y = vetorDesordenado[i];
            vetorDesordenado[i] = vetorDesordenado[j];
            vetorDesordenado[j] = y;
            i++;
            j--;
        }
    }
    
    if(j > comecoDoVetor) {
        ordenar(vetorDesordenado, comecoDoVetor, j);
    }

    if(i < fimDoVetor) {
        ordenar(vetorDesordenado, i, fimDoVetor);
 	}
}

int buscarValor(int *marmores, int valorParaBuscar, int tamanho){
	int i = 0;
	while(i < tamanho && valorParaBuscar > marmores[i])
	      i++;
	      
	if(i < tamanho && valorParaBuscar == marmores[i])
	      return i+1;
	else
	      return 0;
}

int main(){
	int quantMarmore, quantConsultas, valorParaBuscar, posicao, i, cont = 0, numeroDoCaso = 1;
	scanf("%d %d", &quantMarmore, &quantConsultas);
	while(quantMarmore != 0 && quantConsultas != 0){

		int *marmores = (int*)malloc(quantMarmore * sizeof(int));
		int *valoresParaConsulta =(int*) malloc (quantConsultas * sizeof(int));

		for (cont = 0; cont < quantMarmore; cont++){
			scanf("%d", &marmores[cont]);
		}

		for (i = 0; i < quantConsultas; ++i){
			scanf("%d", &valoresParaConsulta[i]);
		}
		
		ordenar(marmores,0,quantMarmore-1);
		
		printf("CASE# %d:\n", numeroDoCaso);
		numeroDoCaso++;

		
		for (i = 0; i < quantConsultas; ++i){
			posicao = buscarValor(marmores,valoresParaConsulta[i],quantMarmore);
			if(posicao != 0){
				printf("%d found at %d\n", valoresParaConsulta[i], posicao);
			}	
			else{
				printf("%d not found\n", valoresParaConsulta[i]);
			}
		}
		scanf("%d %d", &quantMarmore, &quantConsultas);
	}

	return 0;
}