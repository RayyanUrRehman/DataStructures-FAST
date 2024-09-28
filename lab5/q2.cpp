#include<iostream>
using namespace std;

// Write a C++ function to find the length of a singly linked list using tail recursion.

class node{
    public:
    int data;
    node* next;

    node(int data){
        this-> data = data;
        this-> next = NULL;
    }

};

void insert_end(node* head, int data)
{
    node* current = head;
    node* insertNode = new node(data);

    while(current->next != NULL){
        current = current->next;
    }

    current->next = insertNode;
}

void displayLL(node* &head)
{   
    node* current = head;
    while (current!=NULL){
        cout<<current->data<<endl;
        current = current->next;
    }
}


int sizeLL(node* current,int size)
{   
    if (current->next == NULL){
        return size;
    }

    return sizeLL(current->next,size+1);
}

int main()
{
    //making LL
    node* node1 = new node(10);
    
    node* head = NULL;
    head = node1;
    
    node* current = head;

    insert_end(head,20);
    insert_end(head,30);
    insert_end(head,40);
    insert_end(head,50);
    insert_end(head,60);
    displayLL(head);
    cout<<"Size of LL is "<<sizeLL(current,1);
}