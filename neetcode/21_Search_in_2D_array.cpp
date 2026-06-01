#include <iostream>
#include <vector>
using namespace std;

class Sloution
{
public:
    bool search(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int r = mid / col;
            int c = mid % col;
            int val = matrix[r][c];
            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Sloution s;
    int target = 6;
    cout << boolalpha<<"Target Value present on 2D matrix or not : " << s.search(matrix, target);
}