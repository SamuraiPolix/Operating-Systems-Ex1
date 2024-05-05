#include <stdio.h>

void stack_overflow();

// Stack overflow
int main(int argc, char* argv[]){
    int trash = 7;
    printf("AGHAFASHFASH OVERFLOW INCOMING!!!\n");
    stack_overflow();
    printf("%d\n", trash);
    return 0;
}

void stack_overflow(){
    stack_overflow();
}