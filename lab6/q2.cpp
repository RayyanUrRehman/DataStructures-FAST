#include<iostream>
using namespace std;

// Implement a Queue based approach where assume you are the cashier in a supermarket and
// you need to make checkouts. Customer ID’s Are 13,7,4,1,6,8,10. (Note: Use Arrays to
// accomplish this task with enqueue and dequeue).

int Qsize = 10;
class Queue
{
    int arr[10];
    int front;
    int back;

    public:
    Queue(){front=-1;back=-1;}

    void enqueue(int data)
    {
        if (back < Qsize){
            back++;
            arr[back] = data;
        }
        else{
            cout<<"Queue Full"<<endl;
        }
    }

    void dequeue()
    {
        if (front < back){
            front++;
            cout<<arr[front]<<endl;
        }
        else{
            cout<<"Queue empty"<<endl;
        }
    }

    void print()
    {
        for (int i=front+1;i<=back;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};






int main()
{
    Queue que;

    //enqueueing
    que.enqueue(13);
    que.enqueue(7);
    que.enqueue(4);
    que.enqueue(1);
    que.enqueue(6);
    que.enqueue(8);
    que.enqueue(10);

    que.print();

    //dequeueuing
    que.dequeue();
    que.dequeue();

    que.print();

    return 0;
}