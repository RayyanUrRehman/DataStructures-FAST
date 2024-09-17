#include<iostream>
using namespace std;

int maxsize = 10;

class Stack
{
    int arr[10];
    int top;

    public:
    Stack(){top = -1;}

    bool isFull()
    {
        if (top == maxsize-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int data)
    {   
        if (isFull()){
            cout<<"Can not push. limit reached"<<endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    bool isEmpty()
    {
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void pop()
    {
        if (isEmpty()){
            cout<<"Can not pop, stack empty."<<endl;
        }
        else{
            cout<<arr[top];
            top--;
        }
    }

    void Top()
    {
        cout<<arr[top]<<endl;
    }

    void size()
    {
        cout<<top<<endl;
    }
};

int main()
{   
    Stack stack;
    stack.pop();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.size();
    stack.Top();

    return 0;
}