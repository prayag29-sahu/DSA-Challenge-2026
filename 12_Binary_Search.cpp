#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 4;
    cout << BinarySearch(v, target);
}