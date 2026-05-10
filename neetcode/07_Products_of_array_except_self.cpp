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
        int leftProduct{1};
        int rightProduct{1};
        int n = nums.size();
        vector<int> answer(n, 1);

        for (int i{0}; i < n; i++)
        {
            answer[i] *= leftProduct;
            answer[n - 1 - i] *= rightProduct;

            leftProduct *= nums[i];
            rightProduct *= nums[n - 1 - i];
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
    answer = P.ProductOfArrayExceptItself02(nums);
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << " ";

    return 0;
}