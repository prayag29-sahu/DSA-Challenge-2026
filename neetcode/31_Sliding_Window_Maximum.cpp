#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maximum_element_window(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution s;
    vector<int> res = s.maximum_element_window(nums, k);
    for (int i : res)
    {
        cout << i << " ";
    }

}