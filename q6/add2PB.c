// This program adds a new entry the phonebook

#include <stdio.h>
#include <unistd.h>     //
#include <stdlib.h>
#include <fcntl.h>      // open() for files

#define FILENAME "phonebook.txt"

size_t strlen(const char* str){
    size_t len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: ./add2PB <name>,<phone_number>\n");
        exit(EXIT_FAILURE);
    }

    // Make sure input is valid: 1 comma in input and at least one hyphen (in phone number)
    int commas = 0;
    int hyphen = 0;
    for (int i = 0; i < argc; i++){
        int j = 0;
        while (argv[i][j] != '\0'){
            if (argv[i][j] == ','){
                commas++;      // found comma - good
            }
            else if (hyphen != 1 && argv[i][j] == '-'){
                // make sure this hypen is inside the phone number with a least one digit in each of his sides
                if (argv[i][j-1] <= '9' && argv[i][j-1] >= '0' && argv[i][j+1] <= '9' && argv[i][j+1] >= '0'){
                    hyphen++;       // found hyphen in phone number - good
                }
            }
            j++;
        }
    }

    if (commas != 1){        // 0 commas or more than 1 - either way it's a bad input
        fprintf(stderr, "Error! commas found: %d, commas expected: 1.\nUsage: ./add2PB <name>,<phone_number>\n", commas);
        exit(EXIT_FAILURE);
    }

    if (hyphen != 1){
        fprintf(stderr, "Error! Phone number should be written with at least one hyphen '-'.\nExample: ./add2PB Full Name,054-1234567\n");
        exit(EXIT_FAILURE);
    }

    // open file in append mode
    int fd = open(FILENAME, O_CREAT | O_WRONLY | O_APPEND | __O_CLOEXEC);  // __O_CLOEXEC recommended by tidy
    if (fd == -1){
        perror("open");
        exit(EXIT_FAILURE);
    }

    // line break before writing
    if (write(fd, "\n", sizeof(char)) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

    // write name to file
    for (int i = 1; i < argc-1; i++){
        // write name (argv[1] to argv[argc-1] : the one before the number)
        if (write(fd, argv[i], strlen(argv[i])) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }
        // space between names, not in the last one
        if (i < argc - 2 && write(fd, " ", sizeof(char)) == -1){
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // write phone number to file
    if (write(fd, argv[argc-1], strlen(argv[argc-1])) == -1){
        perror("write");
        exit(EXIT_FAILURE);
    }

    // add a line break character (visible \n) at the end of the line
    // if (write(fd, "\\n", 2*sizeof(char)) == -1){
    //     perror("write");
    //     exit(EXIT_FAILURE);
    // }

    // close file
    close(fd);

    return 0;
}
