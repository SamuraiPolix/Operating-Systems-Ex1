#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // INT_MIN INT_MAX
#include <time.h>       // Used to calculate the time it takes for the functions to finish

#define MAX_NUM 74
#define MIN_NUM -25

void generate_random_data (int* arr, int size);
long max_sub_array_sum_n (int* arr, int size);      // n
long max_sub_array_sum_n2 (int* arr, int size);     // n^2
long max_sub_array_sum_n3 (int* arr, int size);     // n^3

int main (int argc, char* argv[]){
    if (argc != 3){
        fprintf(stderr, "ERROR! Please enter 2 arguments (random seed, input size)!\n");
        exit(1);
    }
    
    // Set seed to given number
    srand(atoi(argv[1]));

    int size = atoi(argv[2]);       // save input size requested

    int arr[size];

    clock_t start, end;
    double cpu_time_used;

    // Generate random data
    printf("Generating %d random values:\n", size);
    start = clock();    // start the clock
    generate_random_data(arr, size);
    end = clock();      // end the clock
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;      // calculate in seconds
    printf("Time taken to generate random data: %f seconds\n", cpu_time_used);

    // O(n)
    printf("Running O(n):\n");
    start = clock();    // start the clock
    max_sub_array_sum_n(arr, size);
    end = clock();      // end the clock
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;      // calculate in seconds
    printf("Time taken for O(n): %f seconds\n", cpu_time_used);

    // O(n^2)
    printf("Running O(n^2):\n");
    start = clock();
    max_sub_array_sum_n2(arr, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for O(n^2): %f seconds\n", cpu_time_used);

    // O(n^3)
    printf("Running O(n^3):\n");
    start = clock();
    max_sub_array_sum_n3(arr, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for O(n^3): %f seconds\n", cpu_time_used);

    return 0;
}

// Generating random data
void generate_random_data (int* arr, int size){
    for (int i = 0; i < size; i++){
        arr[i] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;        // set cell to a random value in the range (MIN_NUM, MAX_NUM)
    }
}


// Using Kadane’s Algorithm
// O(n)
long max_sub_array_sum_n (int* arr, int size){
    long total_max = INT_MIN,     // Stores the max sub array sum until now - in the whole array
        curr_max = 0;       // Stores the max sub array sum in the current sum

    for (int i = 0; i < size; i++){
        curr_max += arr[i];     // add current cell to curr_max
        // check to see if the curr_max is better than the total_max
        if (total_max < curr_max){
            total_max = curr_max;       // if curr_max is bigger - update total_max
        }
        else if (curr_max < 0){     // reset current max if it goes negative - negative will lower our sum
            curr_max = 0;
        }
    }
    return total_max;
}

// O(n^2)
long max_sub_array_sum_n2 (int* arr, int size) {
    long total_max = arr[0];

    // For each cell, Iterate over (i, end). sub arrays sum are taken into account in the if statement inside the 2nd for loop
    for (int i = 0; i < size; i++){
        long curr_sum = 0;      // sums all the cells from i to size
        for (int j = i; j < size; j++){
            curr_sum += arr[j];
            if (total_max < curr_sum){
                total_max = curr_sum;   // for each cell, update total_max if current sum is better, so sub arrays are included as well
            }
        }
    }

    return total_max;
}

// O(n^3)
long max_sub_array_sum_n3 (int* arr, int size) {
    long total_max = arr[0];

    // loop through all sub arrays, i and j are "pointers" on the array. k moves between i and j.
    // that way all sub arrays are checked literally
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            long curr_sum = 0;
            // calculate sum of subarray in range [i, j]
            for (int k = i; k <= j; k++) {
                curr_sum += arr[k];
            }
            if (total_max < curr_sum) {
                total_max = curr_sum;       // new total max found
            }
        }
    }
    return total_max;
}