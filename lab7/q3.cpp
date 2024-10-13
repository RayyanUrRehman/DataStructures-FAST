#include<iostream>
using namespace std;


void merge(int* arr,int s, int e)
{       
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    for (int i=0; i<len1; i++){
        arr1[i] = arr[mainIndex++];
    }
    
    mainIndex = mid+1;
    for (int i=0; i<len2; i++){
        arr2[i] = arr[mainIndex++];
    }

    //now sort and merge
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;

    while(index1 < len1 && index2 < len2){
        if (arr1[index1] < arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }
        else{
            arr[mainIndex++] = arr2[index2++];            
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = arr1[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = arr2[index2++];
    }

}


void decMerge(int* arr,int s, int e)
{       
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int(len1);
    int *arr2 = new int(len2);

    int mainIndex = s;

    for (int i=0; i<len1; i++){
        arr1[i] = arr[mainIndex++];
    }
    
    mainIndex = mid+1;
    for (int i=0; i<len2; i++){
        arr2[i] = arr[mainIndex++];
    }

    //now sort and merge
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;

    while(index1 < len1 && index2 < len2){
        if (arr1[index1] > arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }
        else{
            arr[mainIndex++] = arr2[index2++];            
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = arr1[index1++];
    }

    while(index2 < len2){
        arr[mainIndex++] = arr2[index2++];
    }

}


void mergeSort(int* arr, int s, int e)
{
    if (s >= e){
        return ;
    }

    int mid = (s+e)/2;

    //left part sort
    mergeSort(arr, s, mid);

    // right part sort 
    mergeSort(arr, mid+1, e);

    // call merge 
    merge(arr, s, e);
}

void mergeSortD(int* arr, int s, int e)
{
    if (s >= e){
        return ;
    }

    int mid = (s+e)/2;

    //left part sort
    mergeSortD(arr, s, mid);

    // right part sort 
    mergeSortD(arr, mid+1, e);

    // call merge 
    decMerge(arr, s, e);
}


int main()
{
    int n;
    cout<<"Enter number of elements ";
    cin>>n;

    int* arr = new int[n];

    cout<<"Enter elements: "<<endl;

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<endl<<"Ascending: "<<endl;

    mergeSort(arr,0,n);     //ascending

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout<<endl<<"Descending: "<<endl;

    mergeSortD(arr,0,n);    //descending

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    



    return 0;
}