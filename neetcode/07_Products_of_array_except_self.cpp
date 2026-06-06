#include <iostream>
#include <vector>
using namespace std;

class Products_of_array_except_self
{
public:
    // Brute force approach O(n^2)
    vector<int> ProductOfArrayExceptItself(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> results(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                results[i] *= nums[j];
            }
        }
        return results;
    }

    // Optimized approach O(n) using prefix and prefix
    vector<int> ProductOfArrayExceptItself01(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> results(n, 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            results[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = nums.size()-1; i >= 0; --i)
        {
            results[i] *= suffix;
            suffix *= nums[i];
        }
        return results;
    }

// alternate optimized 
    vector<int> ProductOfArrayExceptItself02(vector<int> &nums)
    {
        int prefix=1;
        int suffix=1;
        int n = nums.size();
        vector<int> answer(n, 1);

        for (int i=0; i < n; i++)
        {
            answer[i] *= prefix;
            answer[n - i - 1] *= suffix;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];
        }
        return answer;
    }
};

int main()
{
    Products_of_array_except_self P;
    vector<int> nums = {1, 2, 4, 6};
    vector<int> answer;
    // answer = P.ProductOfArrayExceptItself(nums);
    // answer = P.ProductOfArrayExceptItself01(nums);
    answer = P.ProductOfArrayExceptItself02(nums);
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << " ";

    return 0;
}

// TC: O(n)
// SC: O(n)

// First store the product of all elements to the left of each index.
// Then traverse from right to left and multiply by the product
// of all elements to the right.
// Thus each answer[i] becomes:
//
// (product of left elements) × (product of right elements)

// without using division.