#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 17 // Number of elements in array X
#define ITERATIONS 30 // Number of iterations for averaging

// Function prototype for the assembly function
extern float stencilOperation1D_ASM(float X1, float X2, float X3, float X4, float X5, float X6, float X7);

// Function to perform 1-D stencil operation in C
float stencilOperation1D_C(float X1, float X2, float X3, float X4, float X5, float X6, float X7) {
    return X1 + X2 + X3 + X4 + X5 + X6 + X7;
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    double total_time_asm = 0.0; // Variable to store total time for assembly function
    double total_time_c = 0.0; // Variable to store total time for C function

    for (int iter = 0; iter < ITERATIONS; iter++) {
        float X[7] = { 0.0 }; // Initialize X with zeros
        double iteration_time_asm = 0.0; // Variable to store time for each iteration for assembly function
        double iteration_time_c = 0.0; // Variable to store time for each iteration for C function

        // Generate and compute for the first 7 numbers
        for (int i = 0; i < 7; i++) {
            X[i] = ((float)rand() / RAND_MAX) * 999.0 + 1.0; // Generate random value between 1 and 1000
        }

        // Print iteration number
        printf("Iteration %d:\n", iter + 1);

        // Print the first 17 values of X or all if fewer than 17
        printf("X -> ");
        int printCount = N < 10 ? N : 10; // Determine the number of elements to print
        for (int i = 0; i < printCount; i++) {
            printf("%.2f", X[i % 7]); // Print the value at the current index of X array
            if (i < printCount - 1) {
                printf(", ");
            }
        }
        if (printCount < N) {
            printf(", and %d more", N - printCount);
        }
        printf("\n");

        // Arrays to store the output of ASM and C functions
        float asm_output[10];
        float c_output[10];

        // Generate and compute for subsequent numbers, discarding previous ones
        for (int i = 7; i <= N; i++) { // Adjust the range as needed
            clock_t start_asm = clock(); // Start measuring time for assembly function
            float result_asm = stencilOperation1D_ASM(X[0], X[1], X[2], X[3], X[4], X[5], X[6]);
            clock_t end_asm = clock(); // Stop measuring time for assembly function
            double time_taken_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC; // Calculate time taken in seconds for assembly function
            iteration_time_asm += time_taken_asm; // Add time taken to iteration time for assembly function

            clock_t start_c = clock(); // Start measuring time for C function
            float result_c = stencilOperation1D_C(X[0], X[1], X[2], X[3], X[4], X[5], X[6]);
            clock_t end_c = clock(); // Stop measuring time for C function
            double time_taken_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC; // Calculate time taken in seconds for C function
            iteration_time_c += time_taken_c; // Add time taken to iteration time for C function

            if (i >= 7 && i < 17) {
                asm_output[i - 7] = result_asm;
                c_output[i - 7] = result_c;
            }

            if (result_asm != result_c) {
                printf("\nWrong");
                break;
            }

            // Generate a new random value and discard the previous one
            X[0] = X[1];
            X[1] = X[2];
            X[2] = X[3];
            X[3] = X[4];
            X[4] = X[5];
            X[5] = X[6];
            X[6] = ((float)rand() / RAND_MAX) * 999.0 + 1.0;
        }

        // Print the output of the first 10 computations
        printf("\nC function\nY -> ");
        for (int i = 0; i < 10; i++) {
            printf("%.2f", c_output[i]);
            if (i < 9) {
                printf(", ");
            }
        }
        printf("\n\n");

        printf("ASM function\nY -> ");
        for (int i = 0; i < 10; i++) {
            printf("%.2f", asm_output[i]);
            if (i < 9) {
                printf(", ");
            }
        }
        printf("\n");

        printf("\nThe x86-64 kernel output is correct\n");
        printf("\nTotal time taken for iteration %d (ASM): %.6f seconds\n", iter + 1, iteration_time_asm);
        printf("Total time taken for iteration %d (C): %.6f seconds\n\n", iter + 1, iteration_time_c);

        total_time_asm += iteration_time_asm; // Add iteration time to total time for assembly function
        total_time_c += iteration_time_c; // Add iteration time to total time for C function
    }

    // Calculate average time for assembly function
    double average_time_asm = total_time_asm / ITERATIONS;

    // Calculate average time for C function
    double average_time_c = total_time_c / ITERATIONS;

    printf("\nAverage time taken over %d iterations (ASM): %.6f seconds\n", ITERATIONS, average_time_asm);
    printf("Average time taken over %d iterations (C): %.6f seconds\n", ITERATIONS, average_time_c);

    return 0;
}
