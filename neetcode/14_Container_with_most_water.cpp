#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size() - 1;
        int left = 0;
        int right = n;
        int amount = 0;
        int newamount = 0;
        while (left < right)
        {
            if (heights[left] < heights[right])
            {
                newamount = heights[left] * n;
                ++left;
            }
            else
            {
                newamount = heights[right] * n;
                --right;
            }
            amount = max(amount, newamount);
            --n;
        }
        return amount;
    }
};


int main(){
    vector<int> heights = {1,7,3,4,5,2,3,6};
    Solution s;
    cout<<s.maxArea(heights);
}