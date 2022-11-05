// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]

#include <bits/stdc++.h>
using namespace std;
class Trie
{
public:
    string word;
    bool is_word = false;
    Trie *children[26] = {NULL};
};

class Solution
{
private:
    Trie *root = NULL;

    void insert(string &s)
    {
        Trie *temp = root;
        for (auto &i : s)
        {
            int k = i - 'a';
            if (temp->children[k] == NULL)
            {
                temp->children[k] = new Trie;
            }
            temp = temp->children[k];
        }
        temp->word = s;
        temp->is_word = true;
    }

    void dfs(vector<vector<char>> &board, vector<string> &res, Trie *temp, int i, int j)
    {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || !(temp->children[board[i][j] - 'a']))
            return;

        temp = temp->children[board[i][j] - 'a'];

        if (temp->is_word)
        {
            res.push_back(temp->word);
            temp->is_word = false;
        }

        char temp_char = board[i][j];
        board[i][j] = '*';

        dfs(board, res, temp, i + 1, j);
        dfs(board, res, temp, i, j + 1);
        dfs(board, res, temp, i - 1, j);
        dfs(board, res, temp, i, j - 1);

        board[i][j] = temp_char;

        return;
    }

public:
    Solution()
    {
        root = new Trie;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (auto &s : words)
            insert(s);
        vector<string> res;
        Trie *temp = root;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, res, temp, i, j);

        return res;
    }
};