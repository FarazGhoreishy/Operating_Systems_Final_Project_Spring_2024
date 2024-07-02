#include "types.h"
#include "stat.h"
#include "user.h"

#define MATRIX_SIZE 3

// Return a integer between 0 and ((2^32 - 1) / 2), which is 2147483647.
uint
random(void)
{
  // Taken from http://stackoverflow.com/questions/1167253/implementation-of-rand
  static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
  unsigned int b;
  b  = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b  = ((z2 << 2) ^ z2) >> 27; 
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b  = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b  = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;

  return (z1 ^ z2 ^ z3 ^ z4) / 2;
}

// Return a random integer between a given range.
int
random_range(int lo, int hi)
{
  if (hi < lo) 
  {
    int tmp = lo;
    lo = hi;
    hi = tmp;
  }
  int range = hi - lo + 1;
  return random() % (range) + lo;
}

int main(int argc, char *argv[]) 
{
    int A[MATRIX_SIZE][MATRIX_SIZE];
    int B[MATRIX_SIZE][MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            A[i][j] = random_range(0, 9);
            B[i][j] = random_range(0, 9);
        }
    
    int C[MATRIX_SIZE][MATRIX_SIZE];

    // Multiply the matrices
    for (int i = 0; i < MATRIX_SIZE; i++) 
        for (int j = 0; j < MATRIX_SIZE; j++) 
            for (int k = 0; k < MATRIX_SIZE; k++) 
                C[i][j] += A[i][k] * B[k][j];
    
    printf(1, "----------Matrix Multiplication----------\n");
    printf(1, "Result Matrix =\n");

    for (int i = 0; i < MATRIX_SIZE; i++) 
    {
        for (int j = 0; j < MATRIX_SIZE; j++) 
        {
            printf(1, "%d\t", C[i][j]);
        }
        printf(1, "\n");
    }

    csc(getpid());
    gtat();
    exit();
}
