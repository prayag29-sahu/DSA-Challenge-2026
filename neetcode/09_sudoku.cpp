#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool sudoku(vector<vector<char>> &board)
{
    vector<unordered_set<char>> row(9);
    vector<unordered_set<char>> col(9);
    vector<unordered_set<char>> box(9);
    for (int i = 0; i < board[0].size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
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
    vector<vector<char>> board =   {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
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