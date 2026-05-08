#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    vector<int> Top_K_Frequent_Elements(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for (auto &it : freq)
        {
            int num = it.first;
            int count = it.second;
            bucket[count].push_back(num);
        }
        vector<int> result;
        for (int i = n; i > 0; --i)
        {
            for (int num : bucket[i])
            {
                result.push_back(num);
                if (result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    solution s;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    int k = 2;
    vector<int> results = s.Top_K_Frequent_Elements(nums, k);
    for(int num:results){
        cout << num << " ";
    }
}