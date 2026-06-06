#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Two_Sum
{
public:
    vector<int> TwoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int complemet = target - nums[i];
            if (seen.find(complemet) != seen.end())
            {
                return {seen[complemet], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Two_Sum ts;
    vector<int> v = {3, 4, 5, 6};
    int target = 7;
    vector<int> res = ts.TwoSum(v, target);
    cout << "Print index : [" << res[0] << "," << res[1] << "]";
    cout << "\nPrint Values : [" << v[res[0]] << "," << v[res[1]] << "]";
    return 0;
}
// TC: O(n)
// SC: O(n)
// We traverse the array once while storing previously
// seen numbers in a hash map.
// For each element, we compute its complement
// and check if it already exists in O(1) average time.