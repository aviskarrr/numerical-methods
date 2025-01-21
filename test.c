#include<stdio.h>

int main(){
    int *a;
    int b = 10;
    a = &b;
    int arrp[5]= {1,2,3,4,5};
    a = arrp;
    for (int i = 0; i<5;i++){
        printf("%d\n", *(a+i));
    }
}