#include<iostream>
using namespace std;


void merge(int* arr, int s, int e)
{
    int mid = (s+e)/2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    int* arr1 = new int(l1);
    int* arr2 = new int(l2);

    int mainIndex = s;

    for (int i=0;i<l1;i++){
        arr1[i] = arr[mainIndex++];
    }

    mainIndex = mid+1;
    for (int i=0;i<l2;i++){
        arr2[i] = arr[mainIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainIndex = s;

    while(index1 < l1 && index2 < l2){
        if (arr1[index1] < arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }
        if (arr1[index1] > arr2[index2]){
            arr[mainIndex++] = arr2[index2++];
        }
    }

    while(index1 < l1){
        arr[mainIndex++] = arr1[index1++];
    }
    while(index2 < l2){
        arr[mainIndex++] = arr2[index2++];
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

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}