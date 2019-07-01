#include <stdio.h>
int main()
{
    int i,dias = 0,ano = 0, mes = 0;
    scanf("%d",&i);
    while ( i != 0){
        if (i >= 365){
            ano += 1;
            i -= 365;
        }
        else{
            if( i >= 30){
                i -= 30;
                mes += 1;
            }
            else{
                dias = i;
                i = 0;
            }
        }
    }
    printf("%d ano(s)\n",ano);
    printf("%d mes(es)\n",mes);
    printf("%d dia(s)\n",dias);
    return 0;
}