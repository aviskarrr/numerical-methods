#include<stdio.h>
#include<math.h>

double f(double x){
    return 1+pow(x,3);
}

double com_trapezoid(double a, double b, int n){
    double h = (b-a)/n;
    double integral = 0.0;
    integral += f(a)+ f(b);
    for (int i= 1; i<n;i++){
        double x = a+ i*h;
        integral += 2*f(x);
    }

    integral*=(h/2.0);
    return integral;

    //at n = 4, I = 4.79
    // at n = 8, I = 4.76
    // at n = 15, I = 4.75
    // at n = 20, I = 4.75
    // given function = 1+x^3
}

double simple_trapezoid(double a, double b) {
    double h = b - a; 
    double integral = (h / 2.0) * (f(a) + f(b)); 
    return integral;
    //
}


double com_simpson1by3(double a, double b, int n){
    if(n%2!= 0){
        printf("\n n must be even\n");
        return 0;
    }

    double h = (b-a)/n;
    double integral = 0.0;
    integral += f(a)+ f(b);
    for (int i = 1;i<n;i+=2){
        double x = a+ i*h;
        integral += 4*f(x);
    }

    for (int i = 2;i<n;i+=2){
        double x = a+ i*h;
        integral += 2*f(x);
    }

    integral*=(h/3.0);

    return integral;

    // for n = 4, I = 4.75
    // for n = 8, I = 4.75
    // for n = 16, I = 4.75
    // for n = 20, I = 4.75
    // given function = 1+x^3
    //note this is only for even no of subintervals

}


double simple_simpson1_by_3(double a, double b) {
    double midpoint = (a + b) / 2.0;
    double integral = (b - a) / 6.0 * (f(a) + 4 * f(midpoint) + f(b));
    return integral; 
}


double com_simpson3by8(double a, double b, int n){
    if(n%3!= 0){
        printf("\n n must be multiple of 3\n");
        return 0;
    }

    double h = (b-a)/n;
    double integral = 0.0;
    integral += f(a)+ f(b);

    for (int i = 1;i<n;i+=3){
        double x = a+ i*h;
        integral += 3*f(x);
    }

    for (int i = 2;i<n;i+=3){
        double x = a+ i*h;
        integral += 3*f(x);
    }

    for (int i = 3;i<n;i+=3){
        double x = a+ i*h;
        integral += 2*f(x);
    }

    integral*=(3*h/8.0);

    return integral;

    // for n = 6, I = 4.75
    // for n = 9, I = 4.75
    // for n = 12, I = 4.75
    // for n = 15, I = 4.75
    //conclusion: for n = 3k, I = 4.75
    //why it didnt improved increasing n? -> because the function is cubic, so the simpson 3/8 rule is exact for cubic functions
}

double simple_simpson_3_8(double a, double b) {
    double x1 = (a + b) / 3.0; 
    double x2 = (2 * a + b) / 3.0; 


    double integral = (b - a) / 8.0 * (f(a) + 3 * f(x1) + 3 * f(x2) + f(b));

    return integral;
}

int main(){
    double a, b;

    int n;
    
    printf("\n Please enter the lower limit of the integral: ");
    scanf("%lf", &a);
    printf("\n Please enter the upper limit of the integral: ");
    scanf("%lf", &b);
    printf("\n Please enter the number of subintervals(trapeziods)(n): ");
    scanf("%d", &n);

    double result_trap1 = com_trapezoid(a, b, n);
    double result_trap2 = simple_trapezoid(a, b);
    double result_simpson_1by3_1 = com_simpson1by3(a, b, n);
    double result_simpson_1by3_2 = simple_simpson1_by_3(a, b);
    double result_simpson_3by8_1 = com_simpson3by8(a, b, n);
    double result_simpson_3by8_2 = simple_simpson_3_8(a, b);

    printf("\n (composite trap)the approximate value of integral is %lf\n", result_trap1);
    printf("\n (simple trap)the approximate value of integral is %lf\n", result_trap2);
    printf("\n (composite simpson 1/3)the approximate value of integral is %lf\n", result_simpson_1by3_1);
    printf("\n (simple simpson 1/3)the approximate value of integral is %lf\n", result_simpson_1by3_2);
    printf("\n (composite simpson 3/8)the approximate value of integral is %lf\n", result_simpson_3by8_1);
    printf("\n (simple simpson 3/8)the approximate value of integral is %lf\n", result_simpson_3by8_2);

    return 0;
}

