#include <iostream>
#include <vector>
#include <climits>   
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {                                  
        minPrice = min(minPrice, price); 
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main()
{
    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    vector<int> p2 = {7, 6, 4, 3, 1};
    cout << maxProfit(p1) << "\n";
    cout << maxProfit(p2) << "\n";
}