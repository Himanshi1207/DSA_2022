// Given a binary tree. The task is to find the maximum GCD of the siblings of this tree. You have to return the value of the node whose two immediate children has the maximum gcd.
// If there are multiple such nodes, return the node which has the maximum value.

// Siblings: Nodes with the same parent are called siblings.

// GCD (Greatest Common Divisor) of two positive integers is the largest positive integer that divides both numbers without a remainder.

// Note:
// Return 0 if input tree is empty i.e level of tree is -1.
// Consider those nodes which have a sibling.
// Return 0 if no such pair of siblings found.
 

// Example 1:

// Input:
//               4
//             /   \
//            5     2
//                 /  \
//                3    1
//               /  \
//              6   12

// Output: 3
// Explanation: For the above tree, the maximum
// GCD for the siblings is formed for nodes 6 and 12
// for the children of node 3.
 

// Example 2:

// Input: 
//             1
//           /   \
//         3      5
//       /  \    /  \
//      6    9  4    8

// Output: 5
// Explanation: For the above tree, the maximum
// GCD for the siblings is formed for nodes 4 and 8
// for the children of node 5.
 

// Your Task:
// You don't need to take input. Just complete the function maxGCD() that takes the root node as a parameter and returns the value of the node whose two immediate children has the maximum gcd.

 

// Expected Time Complexity: O(|Number of nodes|) .
// Expected Auxiliary Space: O(1) .

 

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <= Data of a node <= 105

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
public:
    int gcd(int a,int b){
        if(a<b) return gcd(b,a);
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int maxGCD( Node* root)
    {
        queue<Node*> qt;
        pair<int,int> temp={0,0};
        qt.push(root);
        while(!qt.empty()){
            auto t=qt.front();
            qt.pop();
            int a=0,b=0;
            if(t->left){
                a=t->left->data;
                qt.push(t->left);
            }
            if (t->right){
                b=t->right->data;
                qt.push(t->right);
            }
            if(a && b){
                int res=gcd(a,b);
                if(temp.second<=res){
                    temp.first=t->data;
                    temp.second=res;
                }
            }
        }
        return temp.first;
    
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
		cout<<ob.maxGCD(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends