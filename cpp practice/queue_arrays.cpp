#include<iostream>
using namespace std;

int msize = 5;
class queue
{
    int arr[5] = {0,0,0,0,0};
    int front = -1;
    int rear = -1;

    public:

    bool isFull()
    {
        if (front == 4){
            cout<<"Queue full."<<endl;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (rear > front){
            cout<<"Queue empty."<<endl;
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        if (!isFull()){
            front++;
            arr[front] = data;
            cout<<"Element added"<<endl;
        }
    }

    void dequeue()
    {   
        if (!isEmpty()){
            rear++;
            cout<<"Element dequeue: "<<arr[rear]<<endl;
        }

    }

    void printQueue()
    {
        for (int i=rear+1;i<=front;i++){
            cout<<arr[i]<<" ";
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
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);
    // q.dequeue();
    q.printQueue();
    return 0;
}