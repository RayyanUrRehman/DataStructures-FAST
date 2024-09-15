#include<iostream>
using namespace std;


int binarySearch(int arr[], int size, int val) {
    int lb = 0;
    int ub = size - 1;
    
    while(lb <= ub){
        int mid = (lb + ub) / 2;

        if(arr[mid] == val){
            return mid;  
        }
        else if(arr[mid] < val){
            lb = mid + 1;  
        }
        else{
            ub = mid - 1;  
        }
    }
    return lb;
}


void insert(int arr[], int size, int val) {
    int index = binarySearch(arr, size, val);  

    for(int i = size; i > index; i--){
        arr[i] = arr[i - 1];
    }

    arr[index] = val;
}


void display(int arr[], int size) {
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[6] = {12, 32, 34, 24, 60};  
    int size = 5;  
    int val = 34;  //id 23k-06'34'

    int index = binarySearch(arr, size, val);

    if (arr[index] == val){
        cout<<"Value "<<val<<" found at index "<<index<< endl;
    } 
    else{
        cout << "Value not found. So value "<<val <<" inserted at position " << index << "." << endl;
        insert(arr, size, val);
        size++;  
        cout<<"New array: "<<endl;
        display(arr, size);
    }

    return 0;
}
