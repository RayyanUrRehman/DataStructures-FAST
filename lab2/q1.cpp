#include<iostream>
using namespace std;

int main()
{
    int** smallarr = new int*[5]; //first making 5 by 5 jagged

    for (int i=0;i<5;i++){
        smallarr[i] = new int[5];
    }

    //resiizng to 10
    int** smallarr = new int*[10];
    for (int i=0;i<10;i++){
        smallarr[i] = new int[10];
    }
}