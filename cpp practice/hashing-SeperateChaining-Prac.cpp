#include <iostream>
using namespace std;


class Node
{
    public:
    int key;
    int value;
    Node* next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class hashTable
{
    public:
    Node** arr;
    int size = 10;

    hashTable()
    {       
        arr = new Node*[size];
        for(int i=0;i<size;i++){
            arr[i] = nullptr;
        }
    }

    int hashFunc(int k)
    {
        return (k % size);
    }   


    void insert(int k, int v)
    {
        Node* newNode = new Node(k,v);
        int hashNum = hashFunc(k);

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

    void deleteNode(int k, int v)
    {
        int hashnum = hashFunc(k);
        if (arr[hashnum]->value == v){
            arr[hashnum] = arr[hashnum]->next;
        }
        else{
            Node* prev = arr[hashnum];
            Node* current = prev->next;
            while(current->next != nullptr && current->value != v){
                prev = current;
                current = current->next;
            }
            prev->next = current->next;     //deleted!
        }
    }

    void print()
    {
        for (int i=0;i<size;i++){
            cout<<i<<" : ";
            Node* current = arr[i];
            if (arr[i] != nullptr){
                while(current->next != nullptr){
                    cout<<current->value<<" ";
                    current = current->next;
                }
                cout<<current->value<<endl;
            }
            else{
                cout<<" - "<<endl;
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

    table.deleteNode(20,30);
    table.print();

    return 0;

}