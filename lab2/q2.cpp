#include "matrix_multiply.h"

int main()
{
    int Arow = 2;
    int Acol = 3;
    int Bcol = 2;


    // making a b c arrays
    int** A = new int*[Arow];
    int** B = new int*[Acol];
    int** C = new int*[Arow];  //C will have rows of A and col of B

    for (int i = 0; i < Arow; i++) {
        A[i] = new int[Acol];
    }
    for (int i = 0; i < Acol; i++) {
        B[i] = new int[Bcol];
    }
    for (int i = 0; i < Arow; i++) {
        C[i] = new int[Bcol];
    }

    //initiallizing a & b
    A[0][0] = 1;
    A[0][1] = 2; 
    A[0][2] = 3;
    A[1][0] = 4; 
    A[1][1] = 5;
    A[1][2] = 6;

    B[0][0] = 7;
    B[0][1] = 8;
    B[1][0] = 9; 
    B[1][1] = 10;
    B[2][0] = 11; 
    B[2][1] = 12;

    multiply(A,B,C,Arow,Acol,Bcol);

    return 0;
}