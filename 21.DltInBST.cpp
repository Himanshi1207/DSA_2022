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
node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node* inorderSuccessor(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
node *dltInBST(node *root, int key)
{
    if (key < root->data)
    {
        root->left = dltInBST(root->left, key);
    }
    else if(key>root->data)
    {
        root->right = dltInBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = dltInBST(root->right, temp->data);
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);

    // printing inorder
    inorder(root);
    cout << endl;
    root = dltInBST(root, 5);
    inorder(root);
    cout << endl;
    root = dltInBST(root, 1);
    inorder(root);
    return 0;
}