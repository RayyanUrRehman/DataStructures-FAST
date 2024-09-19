#include<iostream>
using namespace std;

// Given a SinglyLinkedList, write a function that remove all duplicate values from the list. Your 
// function should handle the case that if two adjacent nodes are the same, the function should 
// remove the second appearance of the duplicate value.

class node
{
    public:
    node* next;
    int data;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void remove_duplicate(node* head)
{
    node* current = head;
    node* current2 = head;
    node* temp;

    while(current->next != NULL){
        while(current2->next != NULL){
            temp = current2;
            current2 = current2->next;
            if (current2->data == current->data || current2->data == temp->data){
                temp->next = current2->next;
            }
        }
        current = current->next;
        current2 = current->next;
    }
}

void displayLL(node* &head)
{   
    node* current = head;
    while (current!=NULL){
        cout<<current->data<<endl;
        current = current->next;
    }
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

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    insert_end(head,20);
    insert_end(head,20);
    insert_end(head,30);
    insert_end(head,20);
    insert_end(head,40);
    remove_duplicate(head);
    displayLL(head);


    return 0;
}