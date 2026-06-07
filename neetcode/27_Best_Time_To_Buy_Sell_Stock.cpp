#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    // 1st attempt not passes all test cases
    int maxProfit(vector<int> &prices)
    {
        int m = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; ++i)
        {
            m = min(m, prices[i]);
        }
        int i = 0;
        while (prices[i] != m)
        {
            ++i;
        }
        if (i + 1 >= n)
        {
            return 0;
        }
        int mx = 0;
        for (int j = i + 1; j < n; ++j)
        {
            mx = max(mx, prices[j]);
        }
        return mx - m;
    }

};

int main()
{
    Solution s;
    vector<int> prices = {10, 1, 5, 6, 7, 1};
    cout << s.maxProfit(prices);
}