// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

#include <bits/stdc++.h>
using namespace std;

 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution
 {
 public:
     void rangesum(TreeNode *root, int low, int high, int &ans)
     {
         if (root == NULL)
             return;
         if (root->val >= low and root->val <= high)
         {
             ans += root->val;
             rangesum(root->left, low, high, ans);
             rangesum(root->right, low, high, ans);
         }
         else if (root->val < low)
         {
             rangesum(root->right, low, high, ans);
         }
         else if (root->val > high)
         {
             rangesum(root->left, low, high, ans);
         }
     }
     int rangeSumBST(TreeNode *root, int low, int high)
     {
         int ans = 0;
         rangesum(root, low, high, ans);
         return ans;
     }
 };