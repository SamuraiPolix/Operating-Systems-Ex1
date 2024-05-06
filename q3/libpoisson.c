#include "libpoisson.h"
#include <math.h>   // pow()

long double poisson (long double lambda, long double k){
    return ((long double)(pow(lambda, k))/factorial(k)) * (long double)(expf(-lambda));
}

long double factorial(long double n){
    if (n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;    
}

