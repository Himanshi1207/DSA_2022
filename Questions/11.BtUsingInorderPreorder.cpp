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
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
void inorderPrint(struct node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node *Node = new node(curr);
    if (start == end)
    {
        return Node;
    }
    int pos = search(inorder, start, end, curr);
    Node->left = buildTree(preorder, inorder, start, pos - 1);
    Node->right = buildTree(preorder, inorder, pos + 1, end);
}
int main()
{
    int preorder[] = { 1, 2, 4, 3, 5 };
    int inorder[] = { 4, 2, 1, 5, 3 };
    node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}