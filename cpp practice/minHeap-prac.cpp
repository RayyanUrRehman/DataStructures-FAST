#include<iostream>
using namespace std;

class minHeap
{
    public:
    int size;
    int index;
    int* heap;

    minHeap(int s){
        size = s;
        index = 0;
        heap = new int[s];
    }

    void heapifyDown(int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < index && heap[left] < heap[smallest]){
            smallest = left;
        }
        if (right < index && heap[right] < heap[smallest]){
            smallest = right;
        }

        if (smallest != i)
        {
            swap(heap[smallest],heap[i]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i)
    {
        int parent = (i-1)/2;

        if (i > 0 && heap[i] < heap[parent]){
            swap(heap[parent], heap[i]);
            heapifyUp(parent);
        }
    }

    void insert(int v)
    {
        if (index == size){
            cout<<"Full";
            return;
        }

        heap[index] = v;
        heapifyUp(index);
        index++;
    }

    int Delete()
    {
        if (index == 0){
            cout<<"empty";
        }
        int temp = heap[0];
        heap[0] = heap[index-1];
        index--;
        heapifyDown(0);
        return temp;
    }

    void print() {
    for (int i = 0; i < index; i++) {
        cout << heap[i] << " ";
    }
        cout << endl;
    }
};





int main()
{

    // h.insert(10);
    // h.insert(20);
    // h.insert(30);
    // h.insert(5);
    // h.insert(15);
    
    // cout << "Min Heap after insertions: ";
    // h.print();
    
    // h.Delete();
    // cout << " Min Heap after deletion: ";
    // h.print();

    //heapsort
    minHeap h(10);
    int arr[6] = {2,6,1,4,9,8};

    for (int i=0;i<6;i++){
        h.insert(arr[i]);   //made heap
    }
    for (int i=0;i<6;i++){
        arr[i] = h.Delete();
    }
    for (int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}