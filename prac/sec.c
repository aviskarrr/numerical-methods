#include<stdio.h>
#include<math.h>
#define f(x) (x*x-4*x-10)
int main(){
    int step =1;
    double x1,x0,x2, f1,f2,f0, e=0.0001;
    printf("Enter initial guess");
    scanf("%lf%lf", &x1,&x2);
    f1 = f(x1);
    f2 = f(x2);
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do{
        x0 = x2 - (f2*(x2-x1))/(f2-f1);
        f0 = f(x0);
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x1, x2, x0, f0);
        x1 = x2;
        f1 = f2;
        x2 = x0;
        f2 = f0;
        step++;


    }while(fabs(f0)>e);
    return 0;
}