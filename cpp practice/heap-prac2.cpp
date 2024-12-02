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

    }
};



int main()
{
    heap h(7);
    h.insert(25);
    h.insert(10);
    h.insert(35);
    h.insert(5);
    h.insert(30);
    h.insert(20);
    h.insert(15);

    h.print();

    return 0;
}

