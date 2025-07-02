#include <iostream>
//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

       if(head==NULL){
            return head;
        }
        ListNode* current = head;
        ListNode* nextNode = head->next;
        int num=0;
        
        while(current!=NULL){
            current = current->next;
            num++;
        }
        int* arr = new int[num];
        int count=num;
        current = head;
        while(current!=NULL){
            arr[count-1] = current->val;
            count--;
            current = current->next;
        }
        current=head;
        while(current!=NULL){
            current->val = arr[count];
            current = current->next;
            count++;
        }
        return head;
    }
};