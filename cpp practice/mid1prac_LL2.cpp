#include<iostream>
using namespace std;

// Write a function to reverse the specified portion of the given linked list.
// For instance:
// Input:
// Linked List: 1→ 2 → 3 → 4 → 5 → 6 → 7
// Start position = 2
// End position = 5
// Output:
// 1→ 5 → 4 → 3 → 2 → 6 → 7

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


void reverse_specific(node* head, int start, int end)       //has some errors
{   
    node* nextNode;
    node* prevNode;
    node* current = head;

    int pos = 1;
    while(pos != start){
        prevNode = current;
        current = current->next;
        nextNode = current->next;
        pos++;
    }
    
    // Linked List: 1→ 2 → 3 → 4 → 5 → 6 → 7

    int count = pos;
    while(count != end){
        node* temp = nextNode->next;
        prevNode->next = current->next;
        nextNode->next = current;
        current->next = temp;
        count++;        
    }

}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    insert_end(head,20);
    insert_end(head,30);
    insert_end(head,40);
    insert_end(head,50);
    reverse_specific(head,2,4);
    displayLL(head);
    return 0;
}