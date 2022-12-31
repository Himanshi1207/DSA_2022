// Given a linked list of N nodes, sorted in ascending order based on the absolute values of its data,i.e. negative values are considered as positive ones. Sort the linked list in ascending order according to the actual values, and consider negative numbers as negative and positive numbers as positive.


// Example 1:

// Input: 
// List: 1, -2, -3, 4, -5
// Output: 
// List: -5, -3, -2, 1, 4
// Explanation: 
// Actual sorted order of {1, -2, -3, 4, -5}
// is {-5, -3, -2, 1, 4}
 

#include <bits/stdc++.h>
using namespace std;
struct Node
{
	Node* next;
	int data;
};

void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}
class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        if(head==NULL or head->next==NULL)
            return head;
        Node *node,*prev, *next;
        node=next=head;
        prev=NULL;
        if(head->data<0){
            prev=node;
            node=node->next;
        }
        while(node!=NULL){
            if(node->data<0){
                prev->next=node->next;
                next=node->next;
                node->next=head;
                head=node;
                node=next;
            }
            else{
                prev=node;
                node=node->next;
            }
        }
        return head;
    }
};


int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}