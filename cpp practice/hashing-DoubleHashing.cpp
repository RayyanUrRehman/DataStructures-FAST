#include<iostream>
using namespace std;

class element
{
    public:
    int key;
    int val;
    bool isEmpty;

    element():key(0),val(-1),isEmpty(true){};
    element(int k,int v):key(k),val(v),isEmpty(true){};
};


class hashTable
{
    public:
    element** arr;
    int size = 10;

    hashTable(){
        arr = new element*[size]();
        for (int i=0;i<size;i++){
            arr[i] = new element();
        }
    }

    int hash1(int k)
    {
        return k % size;
    }

    int hash2(int k)
    {
        return (7 - (k % 7));
    }

    int doubleHashing(int k, int i)
    {
        return ((hash1(k) + i * hash2(k))) % size;
    }

    void insert(int k, int v)
    {
        int hashNum = hash1(k);
        element* newElement = new element(k,v);

        if (arr[hashNum]->isEmpty == true){
            arr[hashNum] = newElement;
            arr[hashNum]->isEmpty = false;
        }
        else{
            int i=0;
            while(arr[hashNum]->isEmpty != true){
                hashNum = doubleHashing(k,i);
                i++;
            }
            arr[hashNum] = newElement;
            arr[hashNum]->isEmpty = false;
        }
    }

    void print()
    {
        for (int i=0;i<size;i++){
            if (arr[i] != nullptr){
                cout<<arr[i]->val<<" ";
            }
        }
    }

};


int main()
{
    hashTable h;
    h.insert(115,115);
    h.insert(12,12);
    h.insert(87,87);
    h.insert(66,66);
    h.insert(123,123);
    h.print();

    return 0;
}