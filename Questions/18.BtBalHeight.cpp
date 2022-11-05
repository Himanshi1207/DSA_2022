#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}
// time complexity of this function is o(n^2)
bool isBal(node *root)
{
    if (root == NULL)
        return true;
    if (isBal(root->left) == false)
        return false;
    if (isBal(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool OisBal(node *root, int *height)
{
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;
    if (OisBal(root->left, &lh) == false)
        return false;
    if (OisBal(root->right, &rh) == false)
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
//      1
//    /
//   2
//  /
// 3    this bt is unbalanced

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->r1ight->right = new node(7);
    int height = 0;
    if (isBal(root)==true)
    {
        cout << "The Binary tree is Balanced" << endl;
    }
    else
    {
        cout << "The Binary tree is NOT Balanced" << endl;
    }
    if (OisBal(root,&height)==true)
    {
        cout << "The Binary tree is Balanced" << endl;
    }
    else
    {
        cout << "The Binary tree is NOT Balanced" << endl;
    }
    return 0;
}