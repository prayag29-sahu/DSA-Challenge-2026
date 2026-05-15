#include <iostream>
#include <vector>
using namespace std;

class Sorting
{
public:
    void selection_sort(int num[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            int min = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (num[j] < num[min])
                    min = j;
            }
            int temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
    void bubble_sort(int num[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (num[j] > num[j + 1])
                {
                    swap(num[j], num[j + 1]);
                }
            }
        }
    }
    // insertion sort
    void insertion_sort(int arr[], int n)
    {
        for (int i = 1; i < n; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 and arr[j] > key)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // conquer method
    void conquer(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                ++left;
            }
            else
            {
                temp.push_back(arr[right]);
                ++right;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            ++left;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            ++right;
        }
        for (int i = low; i <= high; ++i)
        {
            arr[i] = temp[i - low];
        }
    }

    // Divide method
    void divide(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        divide(arr, low, mid);
        divide(arr, mid + 1, high);
        conquer(arr, low, mid, high);
    }
    // merge sort
    vector<int> merge_sort(vector<int> &arr, int n)
    {
        divide(arr, 0, n);
        return arr;
    }
};

int main()
{
    Sorting s;
    int arr[] = {5, 2, 4, 1, 7, 5, 10, 3, 43, 12, 65, 0, 34, -1};
    int n = 14;
    // s.selection_sort(arr, n);
    // s.bubble_sort(arr, n);
    // s.insertion_sort(arr, n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    vector<int> nums = {5, 2, 4, 1, 7, 5, 10, 3, 43, 12, 65, 0, 34, -1};
    s.merge_sort(nums, nums.size() - 1);
    for (int x : nums)
        cout << x << " ";
}