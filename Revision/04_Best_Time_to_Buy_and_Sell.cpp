#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int buy_sell(vector<int>&nums){
    int minVal = INT_MAX;
    int maxProfit = 0;
    for(int val : nums){
        minVal = min(minVal, val);
        maxProfit = max(maxProfit, val - minVal);
    }
    return maxProfit;
}

int main(){
    vector<int> profit = {7, 1, 5, 3, 6, 2};
    cout << buy_sell(profit);
}