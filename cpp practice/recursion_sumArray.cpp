#include<iostream>
using namespace std;

// Write a recursive function to calculate the sum of all elements in an integer array.

int sumArray(int arr[],int n)
{
    if (n<1){
        return 0;
    }

    return sumArray(arr,n-1) + arr[n-1];
    
}


int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<sumArray(arr,5);
}