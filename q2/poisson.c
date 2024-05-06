#include <stdio.h>
#include <stdlib.h>  // strtold()
#include <math.h>   // pow()

long double factorial(long double n);
long double poisson (long double lambda, long double k);

int main(int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "Error\n");
        return 1;
    }

    long double lambda = strtold(argv[1], NULL),
        k = strtold(argv[2], NULL);

    printf("%Lf\n", poisson(lambda, k));
    return 0;    
}

long double poisson (long double lambda, long double k){
    return ((long double)(pow(lambda, k))/factorial(k)) * (long double)(expf(-lambda));
}

long double factorial(long double n){
    if (n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;    
}

