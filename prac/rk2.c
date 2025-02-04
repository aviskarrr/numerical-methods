#include<stdio.h>
#include<math.h>

double f (double x, double y){
    return x*x + y*y;
}

int main(){
    double x0 = 1, y0 = 1.2, xn = 1.05, h = 0.05;
    int n = (int)((xn-x0)/h);

    double x = x0, y = y0;
    for(int i = 0;i<n;i++){
        y=y+(h/2)*(f(x,y)+f(x+h, y+h*f(x,y)));
        x =x+h;
    }
    printf("%lf %lf",x,y);
    return 0;
}