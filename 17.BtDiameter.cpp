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
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
// time complexity is O(n^2)
int Diameter(node* root){
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    int currdia=lh+rh+1;

    int ldia=Diameter(root->left);
    int rdia=Diameter(root->right);
    return max(currdia,max(ldia,rdia));
}
// optimized code for diameter of BT
// time complexity is O(n)

int ODiameter(node *root,int* height)
{
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldia=ODiameter(root->left,&lh);
    int rdia=ODiameter(root->right,&rh);

    int currdia=lh+rh+1;
    *height=max(lh,rh+1);

    return max(currdia,max(rdia,ldia));
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
    int height=0;
    cout << "The diameter of the Binary tree is " <<Diameter(root)<<endl;
    cout << "The diameter of the Binary tree is " <<ODiameter(root, &height);
    return 0;
}