#include <stdio.h>
int main(){
    int n,m,cont = 0,mat_maior;
    float nota,maior_nota = 0;
    scanf("%d",&n);
    while (cont < n){
        scanf("%d %f",&m,&nota);
        if (nota > maior_nota){
               maior_nota = nota;
               mat_maior = m;
        }
        cont += 1;
    }
    if (maior_nota >= 8){
        printf("%d\n",mat_maior);
    }
    else{
        printf("Minimum note not reached\n");
    }
    return 0;
}