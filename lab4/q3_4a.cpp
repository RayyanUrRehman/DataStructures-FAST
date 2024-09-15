#include<iostream>
using namespace std;

void insertion(int arr[],int size)
{
    for (int i=0;i<size;i++){
        int current = arr[i];
        int j=i-1;

        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


void display(int arr[],string designations[],int size)
{
    cout<<"Arrangement acccording to designation:"<<endl;
    for (int i=0; i<size; i++){
        int temp = arr[i];
        cout<<designations[temp]<<"\t";
    }
}


int main()
{
                             // 0     1     2    3     4     5
    string designations[6] = {"CEO","CTO","CFO","VP","MGR","EMP"};
    int arr[8] = {5,2,4,5,3,1,4,0};

    insertion(arr,8);
    display(arr,designations,8);

    return 0;
}

