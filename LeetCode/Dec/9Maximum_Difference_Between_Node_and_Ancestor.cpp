// Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

// A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

// Example 1:


// Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int ans=0;
    void helper(TreeNode* root,int mini,int maxi)
    {
        if(root==NULL)return; 
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        helper(root->left,mini,maxi);
        helper(root->right,mini,maxi);
        return;
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        helper(root,root->val,root->val);
        return ans;
    }

};