#include<iostream>
using namespace std;

void swap(int* arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int* arr, int s, int e)
{
    int mid = s + (e-s)/ 2;
    int pivot = arr[mid];

    swap(arr, s, mid);

    int cnt = 0;
    for (int i = s + 1; i <= e; i++){
        if (pivot >= arr[i]) {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    
    swap(arr, s, pivotIndex);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex){
        while (arr[i] < arr[pivotIndex]){
            i++;
        }
        while (arr[j] > arr[pivotIndex]){
            j--;
        }

        if (i < pivotIndex && j > pivotIndex){
            swap(arr, i, j);
        }
    }

    return pivotIndex;
}

void quickSort(int* arr, int s, int e)
{
    if (s >= e) {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
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

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
