#include<iostream>
using namespace std;


bool isSafe(int arr[5][5], int n, int x, int y)
{
    if (x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}


bool maze(int arr[5][5], int n, int x, int y, int solArr[5][5])
{
    if (x==n-1 && y==n-1){
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr,n,x,y)){
        solArr[x][y] = 1;

        if (maze(arr,n,x+1,y,solArr)){
            return true;
        }

        if (maze(arr,n,x,y+1,solArr)){
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }
    return false;
}

void display(int solArr[5][5])
{
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            cout<<solArr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[5][5] = {{1,0,1,0,1},
                     {1,1,1,1,1},
                     {0,1,0,1,1},
                     {1,0,0,1,1},
                     {1,1,1,0,1}};

    int solArr[5][5] = {{0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}};

    
    maze(arr,5,0,0,solArr);
    display(solArr);
    
    return 0;
}

