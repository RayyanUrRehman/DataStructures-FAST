#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* next = NULL;
    node* prev = NULL;

    node(int data){
        this->data = data;
    }
};

void displayLL(node* &head)
{   
    node* current = head;
    while (current!=NULL){
        cout<<current->data<<endl;
        current = current->next;
    }
}

void add_at_end(node* &head, int data)
{   
    node* newnode = new node(data);
    node* current = head;
    while(current != NULL && current->next != nullptr){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
}

void display_end_to_start(node* &head)
{
    node* current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    while(current != nullptr){
        cout<<current->data<<endl;
        current = current->prev;
    }
}

void delete_specific_data(node* &head, int data)
{   
    node* current = head;

    while(current != NULL){
        if(current->data == data && current->next == nullptr){
            current = current->prev;
            current->next = NULL; 
        }
        else if(current->data == data && current->prev == nullptr){
            head = current->next;
            current = current->next;
            current->prev = NULL;
        }
        else if(current->data == data){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->prev;
        }
        else{
            current = current->next;
        }
    }
}   

int main()
{
    node* node1 = new node(10);
    node* head = node1;

    add_at_end(head,20);
    add_at_end(head,30);
    add_at_end(head,40);
    displayLL(head);
    cout<<endl;
    delete_specific_data(head,10);
    displayLL(head);

    
    return 0;
}