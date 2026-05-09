#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Hashing
{
public:
    vector<vector<int>> frequencyCount(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i)
        {
            freq[nums[i]]++;
        }
        vector<vector<int>> res;
        for (auto &it : freq)
        {
            res.push_back({it.first, it.second});
        }
        return res;
    }

    void highestLowestOccur(vector<int> &nums)
    {

        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        int maxFreq = 0;
        int minFreq = nums.size();

        int maxEle = -1;
        int minEle = -1;

        for (auto &it : freq)
        {

            int element = it.first;
            int count = it.second;

            if (count > maxFreq)
            {
                maxFreq = count;
                maxEle = element;
            }

            if (count < minFreq)
            {
                minFreq = count;
                minEle = element;
            }
        }

        cout << "Highest Frequency Element: " << maxEle << " -> " << maxFreq << endl;

        cout << "Lowest Frequency Element: " << minEle << " -> " << minFreq << endl;
    }
};
int main()
{
    Hashing h;
    vector<int> nums = {1, 2, 2, 1, 3};
    vector<vector<int>> ans;
    ans = h.frequencyCount(nums);
    cout << "Frequency of each array element : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " -> " << ans[i][1] << endl;
    }
    h.highestLowestOccur(nums);
}