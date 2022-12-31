// Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the roots value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

// Example 1:

// Input: "1(2)(3)" 
// Output: 2 1 3
// Explanation:
//            1
//           / \
//          2   3
// Explanation: first pair of parenthesis contains 
// left subtree and second one contains the right 
// subtree. Inorder of above tree is "2 1 3".

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    Node *treeFromString(string str){
        // code here
        stack<int>s;
        map<int, Node*> m;
        for(int i=0;i<str.size();i++){
            if(str[i]==')'){
                int child=s.top();
                Node* c;
                if(m.find(child)==m.end()){
                    c=new Node(child);
                }
                else{
                    c=m[child];
                }
                s.pop();
                int parent=s.top();
                if(m.find(parent)==m.end()){
                    Node* p=new Node(parent);
                    p->left=c;
                    m[parent]=p;
                }
                else{
                    Node* p=m[parent];
                    p->right=c;
                }
            }
            else{
                int num=0;
                if(str[i]=='(')
                    continue;
                else{
                    while(isdigit(str[i])){
                        num=num*10+(str[i]-'0');
                        i++;
                    }
                    i--;
                    s.push(num);
                }
            }
        }
        if(m.size()==0)
            return new Node(s.top());
        return m[s.top()];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
