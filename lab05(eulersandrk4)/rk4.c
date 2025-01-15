#include<stdio.h>
#include<math.h>

double fd(double x) {
    return 1 + 3 * x * x;
}

double fd2 (double x, double y){
    return x*x + y*y;
}


void qnnob(){
    double x0 = 1, y0 = 1.2, xn = 1.05, h = 0.001;
    //ans at h = 0.05 is 1.277690
    //ans at h = 0.001 is 
    int n = (int)((xn-x0)/h);
    double x = x0, y = y0;

    for (int i = 0; i<n; i++){
        double k1 = h*fd2(x, y);
        double k2 = h*fd2(x+h/2, k1/2);
        double k3 = h*fd2(x+h/2, k2/2);
        double k4 = h*fd2(x+h, y+k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x +h;
    }
    printf("\n\n Qn b. Runge-Kutta 4th order: y(%lf) = %lf\n", x, y);
}

int main(){
    double x0 = 1, y0 = 2, xn = 2.5, h = 0.5;
    int n = (int)((xn-x0)/h);
    double x = x0, y = y0;
    for (int i = 0;i <n;i++){
        double k1 = h*fd(x);
        double k2 = h*fd(x+h/2);
        double k3 = h*fd(x+h/2);
        double k4 = h*fd(x+h);
        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;
    }
    printf("Runge-Kutta 4th order: y(%lf) = %lf\n", x, y);
    qnnob();
}





// Output:
// Runge-Kutta 4th order: y(2.500000) = 18.312500, at h = 0.25
// Runge-Kutta 4th order: y(2.500000) = 18.125000, at h = 0.5