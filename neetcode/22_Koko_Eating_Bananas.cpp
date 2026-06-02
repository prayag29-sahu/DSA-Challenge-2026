#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    bool canEat(vector<int> &piles, int h, int k)
    {
        int hours = 0;
        for (int pile : piles)
        {
            hours += (pile + k - 1) / k;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canEat(piles, h, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> piles = {25, 10, 23, 4};
    int h = 4;
    cout << s.minEatingSpeed(piles, h);
}