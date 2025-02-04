#include<stdio.h>
#include<math.h>


double f(double x) {
    return 1 + 3 * x * x;
}

int main(){
    double x0 = 1, y0 =2, xn = 2.5, h = 0.25;
    int n = (int)((xn-x0)/h);
    double x = x0, y = y0;
    for(int i=0;i<n;i++){
        y = y+ h*f(x);
        x = x+h;
    }

    printf("%lf, %lf", x,y);
    return 0;
}