#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    node *trie;
    Trie()
    {
        trie = new node();
    }
    void insert(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new node();
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};
int main()
{
    Trie *mytrie = new Trie();
    vector<string> words = {"himanshi", "madhavi", "apoorva", "bhavya"};
    for (auto w : words)
    {
        mytrie->insert(w);
    }
    if (mytrie->search("kamal"))
        cout << "KAMAL FOUND" << endl;
    else
        cout << "KAMAL NOT FOUND" << endl;
    if (mytrie->search("himanshi"))
        cout << "HIMANSHI FOUND" << endl;
    else
        cout << "HIMANSHI NOT FOUND" << endl;
    return 0;
}