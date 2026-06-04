#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ans{-1};
        int first{0}, last{(int)nums.size() - 1};

        while (first <= last)
        {
            int middle{first + (last - first) / 2};

            if (nums[middle] == target)
            {
                return middle;
            }

            if (nums[first] <= nums[middle])
            {
                if (nums[first] <= target && target <= nums[middle])
                {
                    last = middle - 1;
                }
                else
                {
                    first = middle + 1;
                }
            }
            else
            {
                if (nums[middle] <= target && target <= nums[last])
                {
                    first = middle + 1;
                }
                else
                {
                    last = middle - 1;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 4, 5, 6, 1, 2};
    cout << "Target value found at index : " << s.search(nums, 4);
}