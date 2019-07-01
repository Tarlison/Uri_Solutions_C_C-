#include <stdio.h>
int main()
{
int n,h = 0,m = 0,s = 0;
scanf("%d",&n);
while (n != 0){
    if (n >= 3600){
        n -= 3600;
        h += 1;
    }
    else{
        if(n >= 60){
        n -= 60;
        m += 1;
        }
        else{
        s = n;
        n = 0;
        }
    }


    }
    printf("%d:%d:%d\n",h,m,s);
    return 0;
}