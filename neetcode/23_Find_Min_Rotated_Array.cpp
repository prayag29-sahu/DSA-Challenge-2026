#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1, ans = INT_MAX;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[low])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << "Minimum value in array : " << s.findMin(nums);
}
