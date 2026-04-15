#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// My 1st attempt
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
        if (sum < 0)
        {
            sum -= nums[i];
        }
    }
    return sum;
}



// // Optimized approach 
// int maxSubArray(vector<int> &nums){
//     int currentSum = nums[0];
//     int maxSum = nums[0];
//     for (int i = 1; i < (int)nums.size(); i++){
//         currentSum = max(nums[i], currentSum + nums[i]);
//         maxSum = max(currentSum, maxSum);
//     }
//     return maxSum;
// }

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
}