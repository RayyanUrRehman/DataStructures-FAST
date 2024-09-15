#include<iostream>
using namespace std;


void interpolationSearch(int arr[],int size,int target)
{
    int lb = 0;
    int ub = size-1;


    while(ub >= lb && target>=arr[lb] && target<=arr[ub]){
        int pos = lb + ((target-arr[lb])*(ub-lb))/(arr[ub]-arr[lb]);
        if (arr[pos] == target){
            cout<<"Target found at: "<<pos;
            break;
        }
        else if(target > arr[pos]){
            lb = pos + 1;
        }
        else{
            ub = pos-1;
        }
    }
    
}


void display(int arr[],int size)
{
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}


//for sorting
void insertion(int arr[],int size)
{
    for (int i=1;i<size;i++){
        int current = arr[i];
        int j = i-1;

        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


bool checkUniformity(int arr[],int size)
{
    int diff = arr[1] - arr[0];  

    for (int i=1; i<size-1; i++) {
        if (arr[i+1] - arr[i] != diff) {
            return false;
        }
    }
    return true;
}


int main()
{
    int size;
    cout<<"Enter size of data: ";
    cin>>size;
    int* arr = new int[size];

    for (int i=0;i<size;i++){
        cout<<"Enter data: ";
        cin>>arr[i];
    }


    insertion(arr,size);

    bool uniform = checkUniformity(arr,size);
    if (uniform == false){
        cout<<"Error! Data not uniform"<<endl;
        return 0;
    }

    cout<<"Sorted array: "<<endl;
    display(arr,size);
    cout<<endl;

    int target;
    cout<<"Enter target: ";
    cin>>target;

    interpolationSearch(arr,size,target);

    return 0;
}