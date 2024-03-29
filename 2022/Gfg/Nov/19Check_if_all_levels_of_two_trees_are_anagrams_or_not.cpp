// Given two binary trees, the task is to check if each of their levels are anagrams of each other or not. 

// Example 1:

// Input:

// Output: 1
// Explanation: 
// Tree 1:
// Level 0 : 1
// Level 1 : 3, 2
// Level 2 : 5, 4

// Tree 2:
// Level 0 : 1
// Level 1 : 2, 3
// Level 2 : 4, 5

// As we can clearly see all the levels of above two binary trees 
// are anagrams of each other, hence return true.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution{

    public:

    bool areAnagrams(Node *a, Node *b)

    {

        if(!a && !b)

        return true;

        if((!a && b) || (a && !b))

        return false;

        queue<Node*>q1;

        queue<Node*>q2;

        q1.push(a);

        q2.push(b);

        while(q1.size()>0)

        {

            int n=q1.size();

            vector<int>v1,v2;

            if(n!=q2.size())

            return false;

            for(int i=0;i<n;i++)

            {

                Node *curr1=q1.front(),*curr2=q2.front();

                q1.pop();q2.pop();

                v1.push_back(curr1->data);

                v2.push_back(curr2->data);

                

                if(curr1->left) q1.push(curr1->left);

                if(curr1->right) q1.push(curr1->right);

                if(curr2->left) q2.push(curr2->left);

                if(curr2->right) q2.push(curr2->right);

            }

            sort(v1.begin(),v1.end());

            sort(v2.begin(),v2.end());

            if(v1!=v2)

            return false;

        }

        return true;

    }

};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}
