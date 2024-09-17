#include<iostream>
using namespace std;


void shellSort(int myarr[], int size){
    for (int gap = size / 2; gap > 0; gap /= 1.5){
        for (int j= gap; j< size; j++){
            int temp = myarr[j];
            int res = j;
            while(res >= gap && myarr[res-gap]>temp){
                myarr[res] = myarr[res - gap];
                res -= gap;
            }
            myarr[res] = temp;
        }
    }
}


int main()
{
    int arr[5] = {3,2,4,1,5};
    shellSort(arr,5);

    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    //gap set to 1.5 instead of 2.

    return 0;
}