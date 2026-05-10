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
};

int main()
{
    Products_of_array_except_self P;
    vector<int> nums = {1, 2, 4, 6};
    vector<int> answer;
    answer = P.ProductOfArrayExceptItself(nums);
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << " ";

    return;
}