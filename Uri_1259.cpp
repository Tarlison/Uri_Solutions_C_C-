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

int main() {
    int numeroDeEntradas,indicePar = 0, indiceImpar = 0, valorInserido,cont = 0,i;

    scanf("%d",&numeroDeEntradas);

    int *vetPar = (int*)malloc( numeroDeEntradas * sizeof(int));
    int *vetImpar = (int*)malloc( numeroDeEntradas * sizeof(int));

    while(cont < numeroDeEntradas){

        scanf("%d", &valorInserido);

        if(valorInserido % 2 == 0){
            vetPar[indicePar] = valorInserido;
            indicePar++;
        }

        if(valorInserido % 2 != 0){
            vetImpar[indiceImpar] = valorInserido;
            indiceImpar = indiceImpar + 1;
        }

        cont++;
    }

    ordenar(vetPar,0,indicePar-1);
    ordenar(vetImpar,0,indiceImpar-1);

    for(i = 0; i < indicePar; i++ ){
            printf("%d\n",vetPar[i]);
    }
    for(i = indiceImpar-1; i >= 0; i--){
    		printf("%d\n",vetImpar[i]);
    }
    free(vetImpar);
    free(vetPar);

    return 0;
}