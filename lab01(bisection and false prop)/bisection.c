// #include <stdio.h>
// #include <math.h>

// // Function definition
// double f(double x) {
//     return cos(x) - x * exp(x);
// }

// int main() {
//     double x0, x1, x2, f0, f1, f2, e;
//     int step = 1;

//     // Input initial guesses and tolerance
//     printf("Enter two initial guesses:\n");
//     while (1) {
//         scanf("%lf%lf", &x0, &x1);
//         f0 = f(x0);
//         f1 = f(x1);

//         if (f0 * f1 > 0.0) {
//             printf("Incorrect initial guesses. They must bracket the root.\n");
//             printf("Enter two new initial guesses:\n");
//         } else {
//             break;
//         }
//     }

//     printf("Enter tolerable error:\n");
//     scanf("%lf", &e);

//     // Implementing Bisection Method
//     printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
//     do {
//         x2 = (x0 + x1) / 2;
//         f2 = f(x2);

//         printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, x1, x2, f2);

//         if (f0 * f2 < 0) {
//             x1 = x2;
//             f1 = f2;
//         } else {
//             x0 = x2;
//             f0 = f2;
//         }

//         step++;
//     } while (fabs(f2) > e);

//     printf("\nRoot is: %.6f\n", x2);
//     return 0;
// }



#include<stdio.h>
#include<math.h>
double bisec_fun(double x){
    return (x*x - 4*x - 10);
}


double bisec_fun2(double x){
    return (4*sin(x)-exp(x));
}

int main(){
    double x1,x2, x0, f1, f2, f0, e;
    int step = 1;
    printf("Enter two initial guesses:\n");
    while(1){
        scanf("%lf%lf", &x1, &x2);
        f1 = bisec_fun2(x1);
        f2 = bisec_fun2(x2);
        if(f1*f2 > 0){
            printf("Incorrect initial guesses. They must bracket the root.\n");
            printf("Enter two new initial guesses:\n");
        }else{
            break;
        }
    }

    printf("Enter the tolorable error:\n");
    scanf("%lf",&e);

    printf("\nstep\t\tx1\t\tx2\t\tx0\t\tf(x0)\n");
    do{
        x0 = (x1+x2)/2;
        f0 = bisec_fun2(x0);
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x1, x2, x0, f0);
        if(f1*f0 > 0){
            x1 = x0;
            f1 = f0;
        }else{
            x2 = x0;
            f2 = f0;
        }
        step++;
    }while(fabs(f0) > e);

    printf("\nRoot is: %.6f\n", x0);
    return 0;

}