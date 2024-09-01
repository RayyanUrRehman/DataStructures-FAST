#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H
#include<iostream>
using namespace std;

//A is one matrix B is second, C is result
void multiply(int** A, int** B, int** C, int Arow, int Acol, int Bcol)
{

    for (int i = 0; i < Arow; i++) {
        for (int j = 0; j < Bcol; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < Arow; i++) {
        for (int j = 0; j < Bcol; j++) {
            for (int k = 0; k < Acol; k++) {
                C[i][j] += A[i][k] * B[k][j];  //A ki row * B ke column
            }
        }
    }

    //displaying output
    for (int i = 0; i < Arow; i++) {
        for (int j = 0; j < Bcol; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

}
#endif