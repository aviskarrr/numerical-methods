#include<stdio.h>
#include<math.h>

double fd(double x) {
    return 1 + 3 * x * x;
}

// double ydash(double x, double y){
//     return 
// }

// h = 0.5 , Runge-Kutta 2nd order: y(2.500000) = 18.312500
// h = 0.25, Runge-Kutta 2nd order: y(2.500000) = 18.171875

int main(){
    double x0 = 1, y0 = 2, xn = 2.5, h = 0.25;
    int n = (int)((xn - x0) / h);
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        y = y + h/2 * (fd(x) + fd(x+h));
        x = x + h;
    }
    printf("Runge-Kutta 2nd order: y(%lf) = %lf\n", x, y);
    return 0;

}