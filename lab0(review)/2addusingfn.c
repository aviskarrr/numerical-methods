#include<stdio.h>

void add(int a, int b){
    printf("Sum of %d and %d is %d",a,b,a+b);
}
int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    add(a,b);
    return 0;
}