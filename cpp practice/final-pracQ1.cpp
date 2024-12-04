#include<iostream>
using namespace std;

class heap
{
    public:
    int* arr;
    int size;
    int index;

    heap(int s){
        size = s;
        arr = new int[size];
        index = 0;
    }

    void insert(int val)
    {
        if (index == size-1){
            cout<<"Heap full.";
            return;
        }

        arr[index] = val;
        index++;

        int i=index;
        while(i > 0){
            int left = i*2+1;
            int right = i*2+1;
            int smallest = i;

            if (left < index && arr[left] < smallest){
                smallest = left;
            }
            if (right < index && arr[right] < smallest){
                smallest = right;
            }

            if (smallest != i){
                swap(arr[smallest], arr[i]);
            }
            else{
                break;
            }
        }
    }

    void print()
    {
        for (int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int* arr, int index, int i)
{
        i=index;
        while(i > 0){
            int left = i*2+1;
            int right = i*2+1;
            int smallest = i;

            if (left < index && arr[left] < smallest){
                smallest = left;
            }
            if (right < index && arr[right] < smallest){
                smallest = right;
            }

            if (smallest != i){
                swap(arr[smallest], arr[i]);
                heapify(arr,index,smallest);
            }
            
        }
}

void heapsort(int* arr, int index)
{
    for (int i=index/2;i>=0;i++){
        heapify(arr,index,i);
    }
}

int main()
{
    heap h(10);
    h.insert(40);
    h.insert(20);
    h.insert(35);
    h.insert(10);
    h.insert(50);
    h.insert(30);
    h.insert(25);

    h.print();

    // cout<<endl<<"Top 3: "<<endl;
    // heapsort(h.arr,h.index);
    // h.print();
    // return 0;
}