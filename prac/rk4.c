#include<stdio.h>
#include<math.h>

double f(double x, double y){
    return x*x + y*y;
}

void rk4(){
    double x0= 1, y0=1.2, xn = 1.05, h = 0.05;
    int n = (int) ((xn-x0)/h);
    double x = x0,y = y0;
    for (int i = 0;i<n;i++){
        double k1 = h * f(x,y);
        double k2 = h * f(x+h/2, k1/2);
        double k3 = h * f(x+h/2, k2/2);
        double k4 = h * f(x+h, y+k3);
        y = y + (k1+ 2*k2+2*k3+k4)/6;
        x = x+h;
    }
    printf("%lf %lf", x,y);
}

void rk2(){
    double x0= 1, y0=1.2, xn = 1.05, h = 0.05;
    int n = (int) ((xn-x0)/h);
    double x = x0,y = y0;
    for (int i = 0;i<n;i++){
        y = y + h/2 * (f(x,y)+f(x+h, y+h*(f(x,y))));
        x = x+h;
    }
    printf("%lf %lf", x,y);
}

void eulers(){
    double x0= 1, y0=1.2, xn = 1.05, h = 0.05;
    int n = (int) ((xn-x0)/h);
    double x = x0,y = y0;
    for(int i =0;i<n;i++){
        y = y+ h*f(x,y);
        x = x+h;
    }
    printf("%lf %lf", x,y);


}

int main(){
    rk2();
    rk4();
    eulers();
    return 0;
}
