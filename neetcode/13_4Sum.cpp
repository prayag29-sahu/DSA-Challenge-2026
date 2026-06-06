#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> FourSum(vector<int> &nums)
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
        for (int j = i + 1; j < n; ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
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
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;

                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = FourSum(nums);
    for (vector<int> &num : res)
    {
        cout << "[";
        for (int n : num)
        {
            cout << n << ", ";
        }
        cout << "]" << endl;
    }
}

