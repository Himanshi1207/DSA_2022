// Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value.

// Example 1

// Input :
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// Output : 4
// Explanation :
// There are 4 subtrees with single values.
// Example 2:

// Input:
//               5
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output: 5
// Explanation:
// There are five subtrees with single values.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution
{
public:
    int ans = 0;
    bool helper(Node *root)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL and root->right == NULL)
        {
            ans += 1;
            return true;
        }
        bool left = helper(root->left);
        bool right = helper(root->right);
        if (!left or !right)
            return false;
        if (root->left and root->left->data != root->data or root->right and root->right->data != root->data)
            return false;
        ans++;
        return true;
    }
    int singlevalued(Node *root)
    {
        // code here
        helper(root);
        return ans;
    }
};

int main()
{

    int t;
    cin >> t;
    getchar();
    while (t--)
    {

        string inp;
        getline(cin, inp);

        Solution ob;

        struct Node *root = buildTree(inp);
        cout << ob.singlevalued(root) << "\n";
    }
    return 0;
}
