#include<iostream>
using namespace std;


void interpolationSearch(int arr[],int size)
{

}


void display(int arr[],int size)
{
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}


//for sorting
void insertion(int arr[],int size)
{
    for (int i=1;i<size;i++){
        int current = arr[i];
        int j = i-1;

        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


int main()
{
    int size;
    cout<<"Enter size of data: ";
    cin>>size;
    int* arr = new int(size);

    for (int i=0;i<size;i++){
        cout<<"Enter data: ";
        cin>>arr[i];
    }

    insertion(arr,size);


    return 0;
}