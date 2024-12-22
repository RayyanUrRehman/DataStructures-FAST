#include<iostream>
using namespace std;

class maxHeap
{
    public:
    int index;
    int size;
    int* heap;

    maxHeap(int s)
    {
        size = s;
        heap = new int[s];
        index = 0;
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (right < index && heap[largest] < heap[right]){
            largest = right;
        }
        if (left < index && heap[largest] < heap[left]){
            largest = left;
        }

        if (largest != i){
            swap(heap[largest], heap[i]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        int parent = (i-1)/2;

        if (i > 0 && heap[i] > heap[parent]){
            swap(heap[i],heap[parent]);
            heapifyUp(parent);
        }
    }

    void insert(int val)
    {
        if (index == size){
            cout<<"FULL";
            return;
        }

        heap[index] = val;
        heapifyUp(index);
        index++;
    }

    int Delete()
    {
        if (index == 0){
            cout<<"Empty";
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
    maxHeap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    h.insert(15);
    
    cout << "Max Heap after insertions: ";
    h.print();
    
    h.Delete();
    cout << " Min Heap after deletion: ";
    h.print();

    return 0;

}