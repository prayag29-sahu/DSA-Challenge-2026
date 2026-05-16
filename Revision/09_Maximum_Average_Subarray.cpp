#include <iostream>
#include <vector>
using namespace std;

int max_avg_sub_array(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n;++i){
        sum += arr[i];
    }
    int maxSum = sum;
    for (int i = n; i < arr.size();++i){
        sum += arr[i];
        sum -= arr[i - n];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int lenght = 4;
    cout<<max_avg_sub_array(nums, lenght);
}