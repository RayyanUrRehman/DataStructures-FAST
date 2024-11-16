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

    return 0;
}