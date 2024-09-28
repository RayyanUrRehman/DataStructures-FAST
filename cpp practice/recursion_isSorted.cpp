#include<iostream>
using namespace std;


bool isSorted(int arr[], int size, int n)
{
    // if(n == size){
    //     return false;
    // }
    if (n == size){
        return true;
    }

    if (arr[n] > arr[n+1]){
        return false;
    }
    else{
        return isSorted(arr,size,n+1);
        
    }
}


int main()
{
    int arr[5] = {1,2,3,40,5};
    cout<<isSorted(arr,5,0);
}