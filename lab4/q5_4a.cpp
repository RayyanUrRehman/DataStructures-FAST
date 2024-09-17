#include<iostream>
using namespace std;


void combSort(int arr[], int n){
    float shrink = 2; 
    bool swapped = true;
    int gap = n; 
    
    while (gap > 1 || swapped){
        gap = gap/shrink;
        if (gap < 1){
            gap = 1; 
        }

        swapped = false;

        for (int i=0; i+gap < n; ++i){
            if (arr[i] > arr[i+gap]){
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swapped = true;
            }
        }
    
    }
}


int main()
{
    int arr[5] = {3,2,4,1,5};
    combSort(arr,5);

    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    //shrink factor set to 2.

    return 0;
    
}