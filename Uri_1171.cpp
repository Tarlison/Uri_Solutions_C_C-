#include <stdio.h>

int main(){
    int numeros[2010], quantidade, cont, aux;
    scanf("%d", &quantidade);
    for(cont = 1; cont <=  2000; cont++) numeros[cont] = 0;
    for(cont = 0; cont < quantidade; cont++){
        scanf("%d", &aux);
        numeros[aux]++;
    }
    for(cont = 1; cont <= 2000; cont++){
        if(numeros[cont] != 0) printf("%d aparece %d vez(es)\n", cont, numeros[cont]);
    }
}