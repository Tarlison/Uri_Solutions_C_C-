#include <stdlib.h>
#include <stdio.h>
int fibonacci(int n, int *calls){
    if (n == 1){
        *calls += 1;
        return 1;
    }
    if (n == 0){
        *calls += 1;
        return 0;
    }
    else{
            *calls += 1;
    }
    return fibonacci(n-1,calls) + fibonacci(n-2,calls);
}
int main(){
    int n,f, valor,calls = 1,*p = &calls;
    scanf("%d",&n);
    while (n!=0){
        scanf("%d",&valor);
        f = fibonacci(valor,p);
        printf("fib(%d) = %d calls = %d\n",valor, calls-2, f);
        *p = 1;
        n--;
    }
    return 0;
}