#include<iostream>
using namespace std;

class heap
{   
    public:
    int* arr;
    int index;
    int size;

    heap(int s){
        size = s;
        arr = new int[size];
        index = 0;
    }


    void insert(int val)
    {
        int i = index;
        arr[index] = val;

        while(i > 0){
            int parent = (i-1)/2;

            if (arr[i] > arr[parent]){
                swap(arr[parent], arr[index]);
                i = parent;
            }
            else{
                break;
            }
        }
        index++;
    }

    void deletion()     //always del the root
    {
        int i=0;
        index--;
        arr[i] = arr[index];

        while(i < index){
            int left = 2*i+1;
            int right = 2*i+2;
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


    void print()
    {
        for (int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

    }
};  




int main()
{
    heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    h.insert(15);

    h.print();

    h.deletion();
    // h.deletion();
    // h.deletion();

    h.print();

    return 0;
}