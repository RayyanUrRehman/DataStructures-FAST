#include<iostream>
using namespace std;

void swap(int* arr,int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int partition(int* arr, int s, int e)
{
    int pivot = arr[s];

    int cnt=0;
    for (int i=s+1;i<=e;i++){
        if (pivot >= arr[i]){
            cnt++;
        }
    }

    int indexPivot = s + cnt;

    swap(arr,s,indexPivot);

    int i=s; 
    int j=e;

    while(i<indexPivot && j>indexPivot){
        while(arr[i] < arr[indexPivot]){
            i++;
        }
        while(arr[j] > arr[indexPivot]){
            j--;
        }
        if (i<indexPivot && j>indexPivot){
            swap(arr,i,j);
        }
    }
    return indexPivot;
}



void quicksort(int* arr, int s, int e)
{
    if (s >= e){
        return;
    }

    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}


int main()
{
    int arr[5] = {6,2,4,1,9};
    int n=5;

    quicksort(arr,0,n-1);

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}