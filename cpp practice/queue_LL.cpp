#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};


class queue
{
    node* front;
    node* rear;

    public:

    queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int val)
    {
        node* newnode = new node(val);
        if (rear == nullptr){
            front = newnode;
            rear = newnode;
        }
        else{
            front->next = newnode;
            front = front->next;
        }
    }

    void dequeue()
    {
        if (rear == nullptr){
            cout<<"queue empty"<<endl;
        }
        else{
            cout<<"dequeued value: "<<rear->data<<endl;
            rear = rear->next;
        }
    }

    void printQ()
    {
        node* rear1 = rear;

        while(rear1 != nullptr){
            cout<<rear1->data<<" ";
            rear1 = rear1->next;
        }
        cout<<endl;
    }
};


int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.printQ();
    q.dequeue();
    q.printQ();
    
    return 0;
}