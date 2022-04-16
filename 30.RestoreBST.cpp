#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right, *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
void calcPointer(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calcPointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
        *prev = root;
        calcPointer(root->right, first, mid, last, prev);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void restoreBST(node *root)
{
    node *first, *mid, *last, *prev;
    first = NULL;
    last = NULL;
    mid = NULL;
    prev = NULL;
    calcPointer(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
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
int main()
{
    node *root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);
    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);
    cout << endl;
    return 0;
}