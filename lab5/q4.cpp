#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim){
    int sum = 0;

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < sizes[i]; j++){
            sum += arr[i][j];  
        }
    }
    return sum;
}

int main(){

    int arr1[] = {1, 2, 3};       
    int arr2[] = {4, 5};          
    int arr3[] = {6, 7, 8, 9};    

    int* jaggedArray[] = {arr1, arr2, arr3};

    int sizes[] = {3, 2, 4};  
   
    int sum = recursiveArraySum(jaggedArray, sizes, 3);  

    cout<<"Sum of elements: "<<sum<<endl; 

    return 0;
}
