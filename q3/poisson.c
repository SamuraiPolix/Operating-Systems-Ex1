#include <stdio.h>
#include <stdlib.h>  // strtol()
#include "libpoisson.h"

int main(int argc, char* argv[]){
    printf("%Lf\n", poisson(2, 1));
    printf("%Lf\n", poisson(2, 10));
    printf("%Lf\n", poisson(2, 2));
    printf("%Lf\n", poisson(3, 3));
    printf("%Lf\n", poisson(100, 3));
    return 0;    
}
