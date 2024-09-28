#include<iostream>
using namespace std;

// Create a C++ program to search for a value in a singly linked list, using non-tail recursion?

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


void searchLL(node* current, int target)
{

    if (current->data == target){
        cout<<"Target found!"<<endl;
        return;
    }

    if (current->next == NULL){
        cout<<"Target not found!"<<endl;
        return;
    }

    searchLL(current->next,target);

    cout<<"Seaching done on "<<current->data<<endl; //backtracked it to show which elemets have been traveresed and checked
    
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
    searchLL(current,30);
    
    
}