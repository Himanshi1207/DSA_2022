// Given a binary tree, find the largest value in each level.


// Example 1:

// Input:
//         1
//        / \
//       2   3 
// Output:
// 1 3
// Explanation:
// At 0 level, values of nodes are {1}
//                  Maximum value is 1
// At 1 level, values of nodes are {2,3}
//                 Maximum value is 3
// Example 2:

// Input:
//         4
//        / \
//       9   2
//      / \   \
//     3   5   7 
// Output:
// 4 9 7
// Explanation:
// At 0 level, values of nodes are {4}
//                  Maximum value is 4
// At 1 level, values of nodes are {9,2}
//                  Maximum value is 9
// At 2 level, values of nodes are {3,5,7}
//                  Maximum value is 7

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


// } Driver Code Ends
//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        //code here
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            // q.pop();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                maxi=max(maxi, front->data);
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
                q.pop();
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

//{ Driver Code Starts.

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
/* Function to get Largest value at each level of Binary Tree */
vector<int> maximumValue(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends