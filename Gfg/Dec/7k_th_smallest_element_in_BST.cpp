// Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// K = 2
// Output: 2
// Explanation: 2 is the 2nd smallest element in the BST

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}




class Solution {
  public:
  void helper(Node *root, int &k, int &ans){
      if(root==NULL)
        return ;
      helper(root->left, k, ans);
      k--;
      if(k==0)
        ans = root->data;
      helper(root->right, k, ans);
      
      
  }
    int KthSmallestElement(Node *root, int K) {
        int ans=-1;
         helper(root, K, ans);
         return ans;
    }
};
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
    }
    return 0;
}