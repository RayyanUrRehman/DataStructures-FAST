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

        if (left < index && heap[left] < smallest){
            smallest = left;
        }
        if (right < index && heap[right] < smallest){
            smallest = right;
        }

        if (smallest != i)
        {
            
        }

    }
};





int main()
{


    return 0;
}