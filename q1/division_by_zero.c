#include <stdio.h>


// Division by zero - Floating point exception
int main(int argc, char* argv[]){
    int num;
    // num = 5/0;       // shows warning when compiling
    // division by 0 without a warning when compiling
    int zero = 0;
    num = 5/zero;
    printf("%d \n", num);
    return 0;
}