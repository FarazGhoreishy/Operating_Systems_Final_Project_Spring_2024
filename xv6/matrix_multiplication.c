#include "types.h"
#include "stat.h"
#include "user.h"

#define MATRIX_SIZE 3

int main(int argc, char *argv[]) 
{
    int A[MATRIX_SIZE][MATRIX_SIZE] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[MATRIX_SIZE][MATRIX_SIZE] = 
    {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[MATRIX_SIZE][MATRIX_SIZE];

    // Multiply the matrices
    for (int i = 0; i < MATRIX_SIZE; i++) 
    {
        for (int j = 0; j < MATRIX_SIZE; j++) 
        {
            for (int k = 0; k < MATRIX_SIZE; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf(1, "Result matrix:\n");

    for (int i = 0; i < MATRIX_SIZE; i++) 
    {
        for (int j = 0; j < MATRIX_SIZE; j++) 
        {
            printf(1, "%d ", C[i][j]);
        }
        printf(1, "\n");
    }

    exit();
}
