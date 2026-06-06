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

        // bucket sort - Bucket index represents the frequency, and the vector stored at that index contains all numbers having that frequency. So bucket[count].push_back(num) means "put this number into the bucket corresponding to its frequency".
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
// TC: O(n) other sortings take O(n log n) so we use bucket sort for O(n)
// SC: O(n)

// First count frequencies using a hashmap.
// Then use bucket sort where the bucket index represents frequency.
// Traverse buckets from highest frequency to lowest
// and collect the first k elements.

// Why Bucket Sort in Top K Frequent but not in Group Anagrams?
// In Top K Frequent Elements, frequencies lie in a bounded range from 1 to n, so frequency can be used directly as a bucket index. In Group Anagrams, the grouping key is a string (sorted word or frequency signature), which does not have a fixed numeric range and therefore cannot be used as a bucket index. Hence we use a hash map instead of bucket sort.