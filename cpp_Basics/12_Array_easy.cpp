#include <iostream>
using namespace std;

class Array_Easy
{
public:
    // Find Largest Element in Array best method in O(n)
    int largestElement(int num[], int size)
    {
        int max = num[0];
        for (int i = 0; i < size; ++i)
        {
            if (max < num[i])
            {
                max = num[i];
            }
        }
        return max;
    }
    // Find Largest Element in Array alternate method using 2 pointer
    int largestElement2Pointer(int num[], int size)
    {
        int left = 0;
        int right = size - 1;
        int maximum = num[0];
        while (left <= right)
        {
            if (num[left] > num[right])
            {
                maximum = max(maximum, num[left]);
            }
            else
            {
                maximum = max(maximum, num[right]);
            }
            ++left;
            --right;
        }
        return maximum;
    }
};

int main()
{
    Array_Easy a;
    int arr[] = {12, 2, 33, 2, 7, 31, 8, 48, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Largest Element of array using iteration : " << a.largestElement(arr, size) << endl;
    cout << "Largest Element of array using 2 pointer : " << a.largestElement2Pointer(arr, size);
}