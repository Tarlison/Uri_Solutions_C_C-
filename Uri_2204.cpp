#include <stdio.h>
#include <string.h>
int main(){
    int i,res,t;
    char a[102],b[102];
    scanf("%d",&t);
    while (t!=0){
        scanf("%s %s",&a,&b);
        if (strcmp(a,b)==0){
            printf("%s\n",a);
        }
        else{
            printf("1\n");
        }
        t = t - 1;
    }
    return 0;
}