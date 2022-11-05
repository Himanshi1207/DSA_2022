#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBSTinBT(node *root)
{
    if (root == NULL)
    {
        return {00, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL and root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    info leftinfo = largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);
    info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);

    if (leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min > root->data)
    {
        curr.min = min(leftinfo.min, root->data);
        curr.max = max(leftinfo.max, root->data);

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    return curr;
}
int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << "largest BST in BT: " << largestBSTinBT(root).ans << endl;
    return 0;
}