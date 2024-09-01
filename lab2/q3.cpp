#include<iostream>
using namespace std;

void checkFriends(bool** array,int row, int col)
{   
    int displayArray[3] = {0,0,0};
    int displayCounter = 0;

    for (int i=0;i<row;i++){
        displayCounter = 0;
        for (int j=0;j<col;j++){
            if (array[i][j] == true ){
                displayArray[displayCounter] = j;
                displayCounter++;
            }
        }
        for (int k=0; k<displayCounter;k++){
            cout<<"The value "<<i<<" has common friends at: "<<displayArray[k]<<endl;
        }
        cout<<endl;
    }
}


int main()
{
    //making 2d array
    int row = 5; int col=5;
    bool** arr = new bool*[col];

    for (int i=0;i<row;i++){
        arr[i] = new bool[col];
    }

    //initializing array
    arr[0][0]=false; arr[0][1]=true;  arr[0][2]=false; arr[0][3]=true;  arr[0][4]=true;
    arr[1][0]=true;  arr[1][1]=false; arr[1][2]=true;  arr[1][3]=false; arr[1][4]=true;
    arr[2][0]=false; arr[2][1]=true;  arr[2][2]=false; arr[2][3]=false; arr[2][4]=false;
    arr[3][0]=true;  arr[3][1]=false; arr[3][2]=false; arr[3][3]=false; arr[3][4]=true;
    arr[4][0]=true;  arr[4][1]=true;  arr[4][2]=false; arr[4][3]=true;  arr[4][4]=false;
    
    checkFriends(arr,row,col);


}