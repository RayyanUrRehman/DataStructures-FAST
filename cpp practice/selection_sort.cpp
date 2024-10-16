#include<iostream>
using namespace std;


void select(int arr[], int n)
{
    int i=0;
    while(i<n){
        int smallestIndex = i;
        int smallest = arr[i];

        for (int j=i+1;j<n;j++){
            if (arr[j] < smallest){
                smallest = arr[j];
                smallestIndex = j;
            }
        }

        int temp = arr[smallestIndex];
        arr[smallestIndex] = arr[i];
        arr[i] = temp;

        i++;
    }
}


int main()
{

    int arr[5] = {5,3,6,1,2};
    int n=5;

    select(arr,n);

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
