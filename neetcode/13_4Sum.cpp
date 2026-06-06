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
| Problem | Time | Space |
    | -- -- -- -- -- --| -- --| -- --|
    | Two Sum(HashMap) | O(n) | O(n) |
    | Two Sum II | O(n) | O(1) |
    | Three Sum | O(n²) | O(1) |
    | Four Sum | O(n³) | O(1) |
    | K - Sum | O(n ^ (k - 1)) | O(1) |

    // After sorting, we fix two elements (i and j) and solve the remaining problem using the two-pointer technique. The outer two loops contribute O(n²), and the two-pointer scan contributes O(n), giving an overall time complexity of O(n³). Auxiliary space is O(1), excluding the output array.