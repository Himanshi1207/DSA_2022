// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true

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
    void helper(TreeNode* root, vector<int> &v){
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
            return;
        }
        helper(root->left, v);
        helper(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        helper(root1, first);
        helper(root2, second);
        if(first==second)
            return true;
        return false;
    }
};