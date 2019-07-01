#include <stdio.h>
int main(){
    float m[12][12],soma = 0, media = 0;
    char op;
    int i = 0, j = 0;
    scanf(" %c",&op);
    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%f",&m[i][j]);
            if (j < i){
                soma += m[i][j];
            }
        }
    }
    if (op == 'S'){
        printf("%.1f\n",soma);
    }
    else{
        media = soma / 66.0;
        printf("%.1f\n",media);
    }
    return 0;
}