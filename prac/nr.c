#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) (x*x - 4*x - 10)


#define g(x) (2*x -4)

int main(){
    double x1,x0,f1,f0,g0,e=0.0001;
    int N=25, step=1;
    printf("Enter initial guess");
    scanf("%lf",&x0);

    printf("\nstep\tx1\tx0\tf0\tf1\n");

    do{
        g0 = g(x0);
        f0 = f(x0);
        if(g0==0){
            printf("Error");
            exit(0);
        }

        x1 = x0 - (f0/g0);
        f1 = f(x1);

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x1, x0, f0,f1);
        x0 = x1;
        step++;
        if(step>N){
            printf("Not Convergent: Maximum iterations reached.\n");
            exit(1);
        }

    }while(fabs(f0)>e);
    return 0;
}