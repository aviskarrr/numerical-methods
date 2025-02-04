#include<stdio.h>
#include<math.h>
double f(double x){
    return 1+pow(x,3);
}


void trap(double a, double b, int n){
    double inte = 0.0;
    double h= ((b-a)/n);
    inte+=f(a)+f(b);
    for(int i = 1;i<n;i++){
        double x = a+i*h;
        inte+=2.0*f(x);
    }
    inte*=h/2.0;
    printf("%lf\n", inte);
}


void s13(double a, double b, int n){
    double inte = 0.0;
    double h= ((b-a)/n);
    inte+=f(a)+f(b);
    for(int i = 1;i<n;i+=2){
        double x = a+i*h;
        inte+=4.0*f(x);
    }
    for(int i = 2;i<n;i+=2){
        double x = a+i*h;
        inte+=2.0*f(x);
    }
    inte*=h/3.0;
    printf("%lf\n", inte);
}

void s38(double a, double b, int n){
    double inte = 0.0;
    double h=  ((b-a)/n);
    inte+=f(a)+f(b);
    for(int i = 1;i<n;i+=3){
        double x = a+i*h;
        inte+=3.0*f(x);
    }
    for(int i = 2;i<n;i+=3){
        double x = a+i*h;
        inte+=3.0*f(x);
    }
    for(int i = 3;i<n;i+=3){
        double x = a+i*h;
        inte+=2.0*f(x);
    }
    inte*=(3*h)/8.0;
    printf("%lf\n", inte);
}

int main(){
    trap(1,2,18);
    s13(1,2,18);
    s38(1,2,18);
    return 0;
}