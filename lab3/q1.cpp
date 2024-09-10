#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val): data(val), next(NULL) {}
};


void insert_end(node* &head, int data)
{
    node* current = head;
    node* insertNode = new node(data);

    while(current->next != NULL){
        current = current->next;
    }

    current->next = insertNode;
}


void displayLL(node* head)
{
    node* current = head;
    while (current != NULL){
        cout<<current->data<<endl;
        current = current->next;
    }
    cout<<endl;
}


void delete_specific_data(node* &head, int data)
{
    node* current = head;
    node* prev = NULL;

    if (head == NULL) return;

    if (head->data == data) {  //if head node needs to be deleted
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;  // If data not found

    prev->next = current->next;
    delete current;
}


node* insert_start(node* &head, int data)
{
    node* temp = new node(data);
    temp->next = head;
    head = temp;
    return head;
}


void EvenOdd(node* &head)
{
    node* current = head;
    node* nextNode = nullptr;

    while (current != NULL) {
        nextNode = current->next;  //store next node before modifying the list

        if (current->data%2==0) {
            int tempData = current->data;
            delete_specific_data(head, current->data);
            head = insert_start(head, tempData);
        }

        current = nextNode;  //move to the next node
    }
}


int main()
{
    node* node1 = new node(10);
    node* head = node1;

    // Constructing linked list
    insert_end(head, 1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);

    cout << "Original Linked List: "<<endl;
    displayLL(head);

    EvenOdd(head);

    cout<<endl;
    cout << "After sorting Even-Odd: "<<endl;
    displayLL(head);

    return 0;
}
