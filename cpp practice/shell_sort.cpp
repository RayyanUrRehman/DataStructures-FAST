#include<iostream>
using namespace std;

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;     

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
                arr[j] = temp;
        }
    }
    return 0;
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
    shellSort(arr,6);
    display(arr,6);
    return 0;
}
