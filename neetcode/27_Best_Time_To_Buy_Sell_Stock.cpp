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

    // Optimized approach
    int maxProfit1(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }

    int maxLoss(vector<int> &prices)
    {
        int maxPrice = prices[0];
        int maxLoss = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            maxPrice = max(maxPrice, prices[i]);
            maxLoss = max(maxLoss, maxPrice - prices[i]);
        }

        return maxLoss;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {10, 1, 5, 6, 7, 1};
    // cout << s.maxProfit(prices);
    //Optimized
    // cout << s.maxProfit1(prices);
    cout << s.maxLoss(prices);
}

// TC = O(n)
// SC = O(1)
