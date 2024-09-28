#include<iostream>
using namespace std;


void linearSearch(int arr[], int size, int target, int n)
{
    if (arr[n] == target){
        cout<<"Target found at "<<n<<endl;
        return;
    }

    if (n == size){
        cout<<"Target not found";
        return;
    }

    return linearSearch(arr,size,target,n+1);

}


int main()
{
    int arr[5] = {1,2,3,4,5};
    linearSearch(arr,5,3,0);
}