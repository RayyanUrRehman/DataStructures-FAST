#include<iostream>
using namespace std;


class Node
{
    public:
    Node* next;
    int key;
    int val;

    Node(int k, int v):key(k),val(v),next(nullptr){};
};

class hashTable 
{
    public:
    Node** arr;
    int size = 10;

    hashTable(){
        arr = new Node*[size]();
    }

    int hashFunc(int k)
    {
        return k % size;
    }

    void insert(int k, int v)
    {   
        int hashNum = hashFunc(k);
        Node* newNode = new Node(k,v);
        if (arr[hashNum]->next == nullptr){
            arr[hashNum]->next = newNode;
        }
        else{
            Node* current = arr[hashNum];
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }
};



int main()
{
    return 0;
}