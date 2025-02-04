#include<stdio.h>
#include<math.h>
double f(double x){
    return x*x - 4*x - 10;
}
int main(){
    double x1,x2,x0,f1,f2,f0,e=0.0001;
    printf("Enter two initial guesses:\n");
    while(1){
        scanf("%lf%lf",&x1,&x2);
        f1 = f(x1);
        f2 = f(x2);
        if(f1*f2>0){
            printf("Invalid guess");
        }
        else
            break;

    }
    printf("\nstep\tx1\tx2\tx0\tf0\n");
    int step =1;
    do{
        x0 = ((x1*f2)-(x2*f1))/(f2-f1);
        f0 = f(x0);
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x1, x2, x0, f0);
        if(f0*f1>0){
            f1 = f0;
            x1=x0;
        }
        else{
            x2 = x0;
            f2 = f0;
        }

        step++;
    }while(fabs(f0)>e);
    return 0;

}