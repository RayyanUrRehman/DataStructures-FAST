#include<iostream>
using namespace std;


void interpolationSearch(int arr[],int size,int target)
{
    int up = size-1;
    int lb = 0;
    int pos; 

    while(target>=arr[lb] && target<=arr[up] && up>=lb){
        pos = lb + ((up-lb)/(arr[up]-arr[lb])) * (target-arr[lb]);

        if (arr[pos] == target){
            cout<<"target found at "<<pos;
            break;
        }
        else if(arr[pos] > target){
            lb = pos + 1;
        }
        else{
            up = pos - 1;
        }
    }

}


int main()
{   
    //array should be sorted and with uniform difference.
    
    int arr[5] = {1,2,3,4,5};
    interpolationSearch(arr,5,3);



    return 0;
}