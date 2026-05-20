#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // two sum 1
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> seen;
        int n = numbers.size();

        for (int i = 0; i < n; ++i)
        {
            int num = target - numbers[i];
            if (seen.find(num) != seen.end())
            {
                return {seen[num], i};
            }
            seen[numbers[i]] = i;
        }
        return {};
    }

    // two sum 2
    vector<int> Two_sum(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
                return {left + 1, right + 1};
            if (sum > target)
                --right;
            else
                ++left;
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 9, 1, 7, 5, 11};
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8};
    int target = 12;
    // vector<int> results = s.twoSum(nums, target);
    vector<int> results = s.Two_sum(sorted, target);
    cout << results[0] << " " << results[1] << endl;

    return 0;
}