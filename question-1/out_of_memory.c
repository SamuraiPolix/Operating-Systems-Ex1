#include <stdio.h>

// Out of memory
int main(int argc, char* argv[]){
    void* p = (void*)0xdeadbeef;
    char* c = (char*)p;
    printf("%c \n", *c);
    return 0;
}