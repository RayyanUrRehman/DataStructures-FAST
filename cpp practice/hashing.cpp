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

    hashTable() {
        arr = new Node*[size];
        for (int i = 0; i < size; i++) {
            arr[i] = nullptr; 
        }
    }

    int hashFunc(int k)
    {
        return k % size;
    }

    void insert(int k, int v)
    {   
        int hashNum = hashFunc(k);
        Node* newNode = new Node(k,v);
        if (arr[hashNum] == nullptr){
            arr[hashNum] = newNode;
        }
        else{
            Node* current = arr[hashNum];
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print()
    {
        for (int i=0;i<size;i++){
            Node* current = arr[i];
            if (arr[i] != nullptr){
                cout<<i<<" : ";
                while(current != nullptr){
                    cout<<current->val<<" ";
                    current = current->next;
                }
                cout<<endl;
            }
            else{
                cout<<i<<" : -"<<endl;
            }
        }
    }
};



int main()
{
    hashTable table;
    table.insert(10,20);
    table.insert(20,30);
    table.insert(30,40);
    table.insert(29,30);
    table.insert(27,90);
    table.insert(23,60);
    table.insert(27,50);

    table.print();


    return 0;
}