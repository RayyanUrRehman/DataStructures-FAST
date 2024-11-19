#include<iostream>
using namespace std;

class Heap{
    public:

    int *arr;
    int size;
    int index;

    Heap(int s){
        arr = new int [s];
        size = s;
        index = 0;
    }

    void Insertion(int val){
        if( index == size -1){
            cout << "Heap is Full " << endl;
            return;
        }
        arr[index] = val;
        
        int i = index;           
        while(i > 0 ){                   
            int parent = (i-1)/2;

            if( arr[parent] < arr[i]){     
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
        index++;
    }

    void Heapify_Up(int *arr, int size, int i ){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if( left < size && arr[largest] < arr[left]){
            largest = left;
        }
        if( right < size && arr[largest] < arr[right]){
            largest = right;
        }
        if( largest != i){
            swap(arr[largest],arr[i]);
            Heapify_Up(arr,size,largest);
        }
    }

    void Make_Max_Heap(int* arr, int size){

        for(int i=size/2; i>=0; i--){   
        Heapify_Up(arr,size,i);
        }
    }

    void Heapify_Down(int *arr, int size, int i ){
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if( left < size && arr[smallest] > arr[left]){
            smallest = left;
        }
        if( right < size && arr[smallest] > arr[right]){
            smallest = right;
        }
        if( smallest != i){
            swap(arr[smallest],arr[i]);
            Heapify_Down(arr,size,smallest);
        }
    }

    void Make_Min_Heap(int* arr, int size){

        for(int i=size/2; i>=0; i--){   
        Heapify_Down(arr,size,i);
        }
    }

    void print(){
        for(int i=0; i< index; i++){
            cout << arr[i] << " " ;
        }
        cout << endl;
    }

};

int main(){
    Heap h(10);

    h.Insertion(7);
    h.Insertion(1);
    h.Insertion(6);
    h.Insertion(2);
    h.Insertion(5);
    h.Insertion(9);
    h.Insertion(10);
    h.Insertion(2);

    cout<<"Original: "<<endl;
    h.print();
    h.Make_Max_Heap(h.arr,8);
    cout<<"Max heap: "<<endl;
    h.print();
    h.Make_Min_Heap(h.arr,8);
    cout<<"Min heap: "<<endl;
    h.print();
    
}