#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool sudoku(vector<vector<char>> &board)
{
    vector<unordered_set<char>> row(9);
    vector<unordered_set<char>> col(9);
    vector<unordered_set<char>> box(9);
    int n = board[0].size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char curr = board[i][j];
            if (curr == '.')
                continue;

            int s = (i / 3) * 3 + (j / 3);
            if (row[i].count(curr) || col[j].count(curr) || box[s].count(curr))
            {
                return false;
            }
            row[i].insert(curr);
            col[j].insert(curr);
            box[s].insert(curr);
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board =
        {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << boolalpha << sudoku(board);
}

// TC: O(81) ≈ O(1)
// SC: O(81) ≈ O(1)

// We maintain three hash-set collections:
// one for rows, one for columns,
// and one for 3x3 sub-boxes.

// For every non-empty cell, we check whether
// the digit already exists in its row,
// column, or sub-box.

// If found, the Sudoku board is invalid.
// Otherwise, we insert the digit into all
// three corresponding sets.