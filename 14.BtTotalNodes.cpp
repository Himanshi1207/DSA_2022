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

int countNodes(node *root)
{
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<"total number of nodes are "<<countNodes(root);
    return 0;
}