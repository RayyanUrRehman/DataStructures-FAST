#include <iostream>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *current1 = l1;
    ListNode *current2 = l2;
    int placeVal = 1;
    int sum = 0;

    while (current1 != nullptr && current2 != nullptr)
    {
        sum += (current1->val + current2->val) * placeVal;
        placeVal *= 10;
        // cout<<"going..."<<sum<<endl;

        current1 = current1->next;
        current2 = current2->next;
    }

    while (current1 != nullptr)
    {
        sum += (current1->val) * placeVal;
        placeVal *= 10;
        current1 = current1->next;
        // current2 = current2->next;
    }

    while (current2 != nullptr)
    {
        sum += (current2->val) * placeVal;
        placeVal *= 10;
        // current1 = current1->next;
        current2 = current2->next;
    }
    cout << sum << endl;

    int digit = sum % 10;
    sum = sum / 10;
    ListNode *l3 = new ListNode(digit);
    ListNode *current3 = l3;

    while (sum % 10 != 0 || sum > 0)
    {
        int digit = sum % 10;
        sum = sum / 10;
        ListNode *newNode = new ListNode(digit);
        current3->next = newNode;
        current3 = current3->next;
    }

    return l3;
}

void insert_end(ListNode *head, int data)
{
    ListNode *current = head;
    ListNode *insertNode = new ListNode(data);

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = insertNode;
}

void displayLL(ListNode *&head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << "val: " << current->val << endl;
        current = current->next;
    }
}

int main()
{
    ListNode *l1 = new ListNode(9);
    ListNode *head1 = l1;
    insert_end(head1, 9);
    insert_end(head1, 9);
    insert_end(head1, 9);
    insert_end(head1, 9);
    insert_end(head1, 9);
    insert_end(head1, 9);

    ListNode *l2 = new ListNode(9);
    ListNode *head2 = l2;
    insert_end(head2, 9);
    insert_end(head2, 9);
    insert_end(head2, 9);

    ListNode *l3 = addTwoNumbers(l1, l2);
    displayLL(l3);

    // displayLL(head1);
    // displayLL(head2);
}
