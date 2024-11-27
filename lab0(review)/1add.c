#include<stdio.h>
int  main()
{
    float a,b;
    printf("Enter two numbers: ");
    scanf("%f %f",&a,&b);
    printf("Sum of %3f and %3f is %3f",a,b,a+b);
    printf("sub of %3f and %3f is %3f",a,b,a-b);
    printf("mul of %3f and %3f is %3f",a,b,a*b);
    printf("div of %3f and %3f is %3f",a,b,a/b);
    return 0;
}