#include<stdio.h>
#include<math.h>
int main(){
    int n;
    float y[100], x[100], sumx= 0, sumxx = 0, sumy = 0, sumxy = 0, a, b;
    printf("Enter the number of data points:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the data points (x and y pairs):\n");
        scanf("%f %f", &x[i], &y[i]);
    }
    for (int i = 0; i < n; i++){
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumxx += x[i] * x[i];
    }
    a = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
    b = (sumy - a * sumx) / n;
    // b = (sumy * sumx - sumxy * n) / (sumx * sumx - sumxx * n);
    // a = (sumx * sumxy - sumxx * sumy) / (sumx * sumx - sumxx * n);
    printf("the value of a is %f and b is %f\n", a, b);
    float predict = a * 150 + b;
    printf("the value of w = 150 is %f", predict);
    printf("The equation of line is: y = %fx + %f\n", a, b);
    return 0;

}