#include<iostream>
using namespace std;


bool isSafe(int arr[], int row, int col)
{
    for (int i=0;i<row;i++){
        if (arr[i] == col || abs(arr[i]-col)==abs(i-row)){
            return false;
        }
    }
    return true;
}

bool queen(int arr[], int n, int x)
{
    if (x == n){
        return true;
    }

    for (int col=0; col<n;col++){
        if (isSafe(arr,x,col)){
            arr[x] = col;
        
            if ((queen(arr,n,x+1))){
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
    int n=4;

    queen(arr,n,0);
    print(arr,n);
    return 0;
}