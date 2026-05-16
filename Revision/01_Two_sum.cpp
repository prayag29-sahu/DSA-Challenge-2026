#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// all posible 2 sum indexes
vector<int> Two_Sum_Indexes(vector<int> &nums, int target)
{
    unordered_map<int, int> val;
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (val.find(complement) != val.end())
        {
            result.push_back(val[complement]);
            result.push_back(i);
        }
        val[nums[i]] = i;
    }
    return result;
}

vector<int> Two_Sum_Values(vector<int> &nums, int target)
{
    unordered_map<int, int> val;
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (val.find(complement) != val.end())
        {
            result.push_back(nums[val[complement]]);
            result.push_back(nums[i]);
        }
        val[nums[i]] = i;
    }
    return result;
}

int main()
{
    vector<int> nums = {2, 9, 6, 7, 11, 4, 5, 3};
    int target = 9;
    vector<int> results_Indexes = Two_Sum_Indexes(nums, target);
    vector<int> results_values = Two_Sum_Values(nums, target);
    int n = results_Indexes.size();
    for (int i = 0; i < n; i = i + 2)
    {
        cout << "Indexes : (" << results_Indexes[i] << ", " << results_Indexes[i + 1] << ") And Values : (" << results_values[i] << ", " << results_values[i + 1] << ")" << endl;
    }
    return 0;
}