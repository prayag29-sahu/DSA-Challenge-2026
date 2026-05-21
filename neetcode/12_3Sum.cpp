#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0)
            {
                ++left;
            }
            else if (sum > 0)
            {
                --right;
            }
            else
            {
                res.push_back({nums[i], nums[left], nums[right]});
                ++left;
                --right;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = ThreeSum(nums);
    for (vector<int> &num : res)
    {
        cout << "[";
        for (int n : num)
        {
            cout << n << ", ";
        }
        cout <<"]"<< endl;
    }
}