// Singly Linked list practice all operations (add,del,search)
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this-> data = data;
        this-> next = NULL;
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


void insert_start(node* &head, int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}


void insert_end(node* head, int data)
{
    node* current = head;
    node* insertNode = new node(data);

    while(current->next != NULL){
        current = current->next;
    }

    current->next = insertNode;
}


void insert_at_index(node* &head, int data, int index)
{
    int count = 0;
    node* current = head;
    while(current != NULL && count+1 != index){
        current = current->next;
        count++;
    }

    if(current==NULL){
        cout<<"Index not found"<<endl;
    }

    node* temp = new node(data);
    temp->next = current->next;
    current->next = temp;
}


void insert_after_data(node* &head, int data, int afterData)
{
    node* current = head;
    node* temp = new node(data);

    while(current != NULL && current->data != afterData){
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
    
}


void delete_at_end(node* &head)
{
    node* current = head;
    node* temp = current;

    while(current->next != NULL){
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
}


void delete_specific_data(node*  &head, int data)
{
    node* current = head;
    node* temp = current;

    while(current->data != data){
        temp = current;
        current = current->next;
    }

    temp->next = current->next;
    current->next = NULL;
}


void delete_start(node* &head)
{
    head = head->next;
}


void search_data(node* &head, int data)
{
    node* current = head;
    int index = 0;

    while(current != NULL && current->data != data){
        current = current->next;
        index++;
    }

    if(current == NULL){
        cout<<"Item Not found"<<endl;
    }
    else{
        cout<<"Item found at index: "<<index;
    }

}

int main()
{   
    node* node1 = new node(10);
    
    node* head = NULL;
    head = node1;

    insert_end(head,20);
    insert_end(head,30);
    insert_end(head,40);
    displayLL(head);
    cout<<endl<<endl;

    return 0;
}