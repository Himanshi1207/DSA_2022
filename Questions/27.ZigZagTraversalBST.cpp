#include <bits/stdc++.h>
using namespace std;
//             1
//           /  \
//         2       3
//           \      \
//            4       5
//         /    \ 
//        6      7
//   ZIGZAG TRAVERSAL 1,3,2,4,5,7,6
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
void zigzagTraversal(node *root)
{
    if(root==NULL){
        return;
    }
    stack<node *> currLevel;
    stack<node *> nextLevel;
    bool ltr = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        node *temp = currLevel.top();
        currLevel.pop();
        if (temp != NULL)
        {
            cout << temp->data <<" ";
            if (ltr)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            ltr=!ltr;
            swap(currLevel,nextLevel);
        }
    }
}
int main()
{
    node *root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}