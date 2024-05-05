#include <stdio.h>
#include <stdlib.h>  // strtol()
#include <math.h>   // pow()

long factorial(int n);
long double poisson (long double lambda, long double k);

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Error\n");
        return 1;
    }

    long double lambda = strtol(argv[1], NULL, 10),
        k = strtol(argv[2], NULL, 10);

    printf("%Lf\n", poisson(lambda, k));
    return 0;    
}

long double poisson (long double lambda, long double k){
    return (pow(lambda, k)/factorial(k)) * expf(-(int)lambda);
}

long factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;    
}

