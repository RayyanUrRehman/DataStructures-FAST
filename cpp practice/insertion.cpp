#include<iostream>
using namespace std;


void insertion(int arr[],int size)
{
    for (int i=1;i<size;i++){
        int current = arr[i];
        int j = i-1;

        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


void display(int arr[],int size)
{
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[6] = {5,4,2,8,9,1};
    insertion(arr,6);
    display(arr,6);
    return 0;
}