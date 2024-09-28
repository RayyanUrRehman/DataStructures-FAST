#include<iostream>
using namespace std;

// rat/lion maze question

bool isSafe(int arr[5][5], int x, int y,int n)
{
    if (x<n && y<n && arr[x][y] == 1){
        return true;
    }
    return false;
}


bool lionMaze(int arr[5][5], int x, int y, int n, int solArr[5][5])
{
    if ((x==(n-1)) && (y==(n-1))){
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr,x,y,n)){
        solArr[x][y] = 1;
        
        if (lionMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if (lionMaze(arr,x,y+1,n,solArr)){
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

    lionMaze(arr,0,0,5,solArr);
    display(solArr);

    return 0;
}