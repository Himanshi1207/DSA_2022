// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
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
    long long totalsum = 0, mod = 1e9 + 7, ans = 0;
    int sumTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        long long sum = root->val + sumTree(root->left) + sumTree(root->right);
        ans = max(ans, (totalsum - sum) * sum);
        return sum;
    }
    int maxProduct(TreeNode *root)
    {
        totalsum = sumTree(root);
        sumTree(root);
        return ans % mod;
    }
};