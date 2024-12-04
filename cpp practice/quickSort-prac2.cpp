#include<iostream>
using namespace std;


int partition(int* arr, int s ,int e)
{
    int pivot = arr[s];
    int cnt=0;

    for (int i=s+1; i<=e; i++){
        if (pivot > arr[i]){
            cnt++;
        }
    }
    int pivotIndex = s + cnt;

    swap(arr[s],arr[pivotIndex]);

    int i=s;
    int j=e;

    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] < arr[pivotIndex]){
            i++;
        }
        while(arr[j] > arr[pivotIndex]){
            j--;
        }
        swap(arr[i], arr[j]);
    }

    return pivotIndex;
}


void quickSort(int* arr, int s, int e)
{
    if (s >= e){
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}




int main()
{
    int arr[5] = {5,2,4,1,3};
    quickSort(arr,0,4);

    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}