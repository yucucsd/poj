#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        double* x = new double[n];
        double* y = new double[n];
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        printf("%d",n);
        for (int i = 0; i < n; i++){
            printf(" %lf %lf", (x[i] + x[(i + 1) % n]) / 2, (y[i] + y[(i + 1) % n]) / 2);
        }
        printf("\n");
    }
}
