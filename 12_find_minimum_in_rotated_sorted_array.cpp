#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1st attempt using 2 pointer
// int findMin(vector<int> &nums)
// {
//     int size = nums.size();
//     int left = 0;
//     int right = size - 1;
//     int mi = 20000;
//     int m = 0;
//     while (left < right)
//     {
//         if (nums[left] > nums[right])
//         {
//             m = nums[right];
//             mi = min(m, mi);
//         }
//         else
//         {
//             m = nums[left];
//             mi = min(m, mi);
//         }
//         ++left;
//         --right;
//     }
//     return mi;
// }

// Optimized using binary search
int findMin(vector<int> &nums){
    int left = 0;
    int right = nums.size() - 1;
    while(left<right){
        if(nums[left]<nums[right])
            return nums[left];
        int mid = left + (right - left) / 2;
        if(nums[mid]>nums[right]) {
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    return nums[left];
}

int main()
{
    vector<int> v1 = {4, 5, 6, 7, 1, 2};
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(v1);
}