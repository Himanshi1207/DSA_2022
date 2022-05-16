#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = 0; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
struct node
{
    int key;
    node *left, *right;
};
node *newNode(int key)
{
    node *n = new node;
    n->key = key;
    n->left = n->right = NULL;
    return n;
}
void getVerticalOrder(node *root, int hdis, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);
    map<int, vector<int>> m;
    int hdis = 0;
    getVerticalOrder(root, hdis, m);

    map<int, vi>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->ss).size(); i++)
            cout << (it->ss)[i] << " ";
        cout << endl;
    }

    return 0;
}