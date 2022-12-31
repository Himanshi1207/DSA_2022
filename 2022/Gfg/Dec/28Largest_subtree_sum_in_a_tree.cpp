// Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

// Example 1:

// Input:
//               1
//             /   \
//            2      3
//           / \    / \
//          4   5  6   7
// Output: 28
// Explanation: 
// As all the tree elements are positive,
// the largest subtree sum is equal to
// sum of all tree elements.

#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution {
  public:
    int res;
    int dfs(Node* root) {
        if(!root) return 0;
        int sum = root->data + dfs(root->left) + dfs(root->right);
        res = max(res, sum);
        return sum;
    }
    
    int findLargestSubtreeSum(Node* root) {
        res = -1e9;
        dfs(root);
        return res;
    }
};

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.findLargestSubtreeSum(root) << endl;
    }
    return 0;
}
