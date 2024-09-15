#include<iostream>
using namespace std;


void bubbleSort(int arr[],int size)
{
    int temp=0;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if (arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    int array[10] = {5,1,3,6,2,9,7,4,8,10};
    bubbleSort(array,10);
    display(array,10);
}