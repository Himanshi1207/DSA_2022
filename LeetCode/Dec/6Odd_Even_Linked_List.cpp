// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
        
        ListNode* p=head;
        ListNode* fhead=NULL;
        int count=0;
        while(p->next!=NULL && p->next->next!=NULL)
        {
            ListNode* temp=p->next;
            p->next=p->next->next;
            temp->next=temp->next->next;
            count++;
            if(count==1)
            fhead=temp;

            p=p->next;
        }
        
        p->next=fhead;
        return head;
    }
};