#include "libpoisson.h"
#include <math.h>   // pow()

long double poisson (long double lambda, long double k){
    return (pow(lambda, k)/factorial(k)) * expf(-(int)lambda);
}

long factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;    
}

