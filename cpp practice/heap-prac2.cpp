#include<iostream>
using namespace std;


class heap
{
    public:
    int* arr;
    int index;
    int size;

    heap(int s)
    {
        size = s;
        arr = new int[s];
        index = 0;
    }

    void insert(int val)
    {
        if (index == size){
            cout<<"Heap full";
            return;
        }

        //insert val at end
        int i = index;
        arr[index] = val;

        while(i > 0){
            int parent = (i-1)/2;
            if (arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
        index++;
        cout<<"inserted "<<val<<endl;
    }

    void print()
    {
        for (int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }
    }

    void del()
    {   
        if (index == 0){
            cout<<"Empty heap";
        }

        index--;
        arr[0] = arr[index];

        int i = 0;
        while(i < index){
            int left = (i * 2) + 1;
            int right = (i * 2) + 2;
            int largest = i;

            if (left < index && arr[left] > arr[largest]){
                largest = left;
            }
            if (right < index && arr[right] > arr[largest]){
                largest = right;
            }

            if (largest != i){
                swap(arr[largest], arr[i]);
                i = largest;
            }
            else{
                break;
            }
        }
    }

    void minHeapify(int i)
    {
        while(i < index){
            int left = (i*2)+1;
            int right = (i*2)+2;
            int smallest = i;

            if (left < index && arr[i] > arr[left]){
                smallest = left;
            }
            if (right < index && arr[i] > arr[right]){
                smallest = right;
            }

            if (smallest != i){
                swap(arr[i], arr[smallest]);
                minHeapify(smallest);
            }
            
        }
    }
};



int main()
{
    heap h(8);
    h.insert(25);
    h.insert(10);
    h.insert(35);
    h.insert(5);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(40);

    h.print();
    cout<<endl;

    // h.del();
    // h.print();

    // for (int i=(h.index/2-1);i>0;i++){
    //     h.minHeapify(i);
    // }
    h.print();


    return 0;
}

