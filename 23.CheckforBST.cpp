#include <iostream>
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
bool checkforBST(node *root, node *min = NULL, node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftValid = checkforBST(root->left, min, root);
    bool rightValid = checkforBST(root->right, root, max);

    return leftValid and rightValid;
}
int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(8);
    if (checkforBST(root, NULL, NULL))
    {
        cout << "Valid";
    }
    else
    {
        cout << "invalid";
    }
    return 0;
}