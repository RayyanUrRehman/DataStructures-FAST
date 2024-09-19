#include<iostream>
using namespace std;

// Implement a recursive binary search function. Given a sorted array and a target value, 
// determine if the target exists in the array. If it does, return its index; otherwise, return -1


int binarySearch(int arr[],int target, int lb, int up)
{
    if (up<lb){
        cout<<"Target not found!";
        return -1;
    }
    int mid = (up+lb)/2;
    if (arr[mid] == target){
        cout<<"Target found! at index "<<mid;
        return mid;
    }
    else if(mid < target){ 
        binarySearch(arr,target,mid+1,up);
    }
    else{
        binarySearch(arr,target,lb,mid-1);
    }
}


int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    binarySearch(arr,4,0,7);
}