// This program adds a new entry the phonebook

#include <stdio.h>
#include <unistd.h>     //
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Usage: add2PB <name>,<phone_number>\n");
        exit(EXIT_FAILURE);
    }

    // TODO - make sure input is good

    // open file in append mode
    int fd = fopen("phonebook.txt", "a");
    if (fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    // write to file
    if (write(fd, argv[1], sizeof(argv[1])) == -1){
        if (write(fd, "\\n", 2*sizeof(char)) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);

    return 0;
}