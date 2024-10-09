#include<iostream>
using namespace std;


void merge(int* arr, int s, int e)
{
    int mid = (s+e)/2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    int* arr1 = new int(l1);
    int* arr2 = new int(l2);

    int mainIndex = 0;

    for (int i=0;i<l1;i++){
        
    }

}

void mergesort(int* arr, int s, int e)
{
    if (s >= e){
        return;
    }

    int mid = (s+e)/2;

    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}

int main()
{
    int arr[5] = {6,2,9,1,5};
    int n = 5;

    mergesort(arr,0,n-1);
    return 0;
}