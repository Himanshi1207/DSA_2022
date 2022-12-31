// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 

// Example 1:


// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int>hash;
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col] != '.')
                {
    
                    string r= "row"+to_string(row)+to_string(board[row][col]);
                    string c= "col"+to_string(col)+to_string(board[row][col]);
                    int b = (row/3) * 3 + (col/3);
                    string box= "box"+ to_string(b) + to_string(board[row][col]);

                    if(hash[r] != 1 && hash[c] != 1 && hash[box] != 1){
                        hash[r]=1;
                        hash[c]=1;
                        hash[box]=1;
                    }else{
                        return false;
                    }

                    }
                
            }
        }
        
        return true;
    }
};