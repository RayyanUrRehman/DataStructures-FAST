#include<iostream>
using namespace std;

class node
{   
    public:
    node* prev;
    int data;

    node(int val){
        prev = nullptr;
        data = val;
    }
};


class stack
{
    node* top;

    public:

    stack(){top = nullptr;}

    void push(int val)
    {
        node* node1 = new node(val);
        node1->prev = top;
        top = node1;
        cout<<"inserted "<<val<<" in stack"<<endl;
    }

    void pop()
    {
        cout<<"Top of stack popped"<<endl;
        cout<<top->data<<endl;

        top = top->prev;
    }

    void isEmpty()
    {
        if (top == NULL){
            cout<<"Stack is empty."<<endl;
        }
    }

    void display()
    {
        node* current = top;
        while(current != NULL){
            cout<<current->data<<" ";
            current = current->prev;
        }
    }

    int sum()
    {
        node* current = top;
        int sum=0;
        while(current != nullptr){
            sum += current->data;
            current = current->prev;
        }
        return sum;
    }

};


int main()
{
    stack Stack;
    Stack.push(10);
    Stack.push(20);
    Stack.push(30);
    Stack.push(40);

    Stack.pop();
    Stack.pop();

    Stack.push(50);
    Stack.display();
    cout<<endl;
    cout<<"Sum of entire stack is: "<<Stack.sum();

    

    return 0;
}