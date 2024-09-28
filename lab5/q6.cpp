#include<iostream>
using namespace std;

// queen/flag qs

bool isSafe(int arr[],int x, int y)
{
    for (int i=0;i<x;i++){
        if (arr[i] == y || abs(arr[i]-y)==abs(i-x)){
            return false;
        }
    }
    return true;
}

bool flags(int arr[],int n, int x)
{
    if(x==n){
        return true;
    }

    for (int y=0;y<n;y++){
        if (isSafe(arr,x,y)){
            arr[x] = y;

            if (flags(arr,n,x+1)){
                return true;
            }

            arr[x] = -1;
        }
    }
    return false;
}

int print(int arr[], int n) {
    int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == j) {
                cout << " F "; 
                count++;
            } else {
                cout << " 0 ";  
            }
        }
        cout << endl;
    }
    return count;
}

int main()
{
    int arr[4] = {-1,-1,-1,-1};
    flags(arr,4,0);
    int count = print(arr,4);
    cout<<"Total numbr of flags: "<<count;
    return 0;
}