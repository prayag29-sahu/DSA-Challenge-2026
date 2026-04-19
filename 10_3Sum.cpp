#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> Sum_3(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                ++j;
                while (j < k && nums[j] == nums[j - 1])
                    ++j;
            }
            else if (sum > 0)
            {
                --k;
            }
            else
            {
                ++j;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = Sum_3(v1);
    for (auto &t : r1)
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "]\n";
    /* [-1,-1,2] and [-1,0,1] */
}