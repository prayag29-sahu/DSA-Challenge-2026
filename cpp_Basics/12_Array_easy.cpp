#include <iostream>
using namespace std;

class Array_Easy
{
public:
    // Find Largest Element in Array best method in O(n)
    int largestElement(int num[], int size)
    {
        int max = num[0];
        for (int i = 1; i < size; ++i)
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

    // find second largest element 2,4,1,6,3,7,4
    void secondLargestElement(int num[], int n)
    {
        int first = num[0]; // 2
        int second;         // . ,
        for (int i = 1; i < n; ++i)
        {
            if (first < num[i])
            {                   // 2<4 t, 4<1 f, 4<6 t, 6<3 f, 6<7 t, 7<4 f
                second = first; // 2 , 4 , 6
                first = num[i]; // 4 , 6 , 7
            }
        }
        cout << "First Largest Element of array : " << first << " and Second Largest Element of array : " << second;
    }

    // find second smallest and second largest
    void SecondSmallestSecondLargest(int num[], int n)
    {
        if (n < 2)
        {
            cout << "-1 -1";
        }
        int smallest = num[0], SecSmallest = num[0], largest = num[0], Seclargest = num[0];
        for (int i = 1; i < n; ++i)
        {
            if (num[i] < smallest)
            {
                SecSmallest = smallest;
                smallest = num[i];
            }
            else if (num[i] < SecSmallest && num[i] > smallest)
            {
                SecSmallest = num[i];
            }
            if (largest < num[i])
            {
                Seclargest = largest;
                largest = num[i];
            }
            else if (Seclargest < num[i] && num[i] < largest)
            {
                Seclargest = num[i];
            }
        }
        cout << "\nSecond Largest Element in array : " << Seclargest << " and Second Smallest element in array : " << SecSmallest;
    }

    // check array is sorted or not
    bool isSorted(int num[], int n)
    {
        for (int i = 1; i < n; ++i)
        {
            if (num[i] < num[i - 1])
            {
                return false;
            }
        }
        return true;
    }

    bool isSortedAscDesc(int arr[], int n)
    {
        if (n <= 1)
            return true;
        int i = 1;
        while (i < n && arr[i] == arr[i - 1])
            i++;
        if (i == n)
            return true;
        bool ascending = arr[i] > arr[i - 1];
        for (; i < n; i++)
        {
            if (ascending)
            {
                if (arr[i] < arr[i - 1])
                    return false;
            }
            else
            {
                if (arr[i] > arr[i - 1])
                    return false;
            }
        }
        return true;
    }

    // Remove Duplicates in-place from Sorted Array
    int removeDuplicate(int nums[], int n) // 1,1,2,2,2,3,3
    {
        int i = 0;
        for (int j = 1; j < n; ++j)
        {
            if (nums[j] != nums[i]) // f, t, f,f, t
            {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    // Left Rotate the Array by One
    void leftRotation(int num[], int n)
    {
        int first = num[0];
        for (int i = 1; i < n; ++i)
        {
            num[i - 1] = num[i];
        }
        num[n - 1] = first;
    }
};

int main()
{
    Array_Easy a;
    int arr[] = {12, 2, 33, 2, 7, 31, 8, 48, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Largest Element of array using iteration : " << a.largestElement(arr, size) << endl;
    cout << "Largest Element of array using 2 pointer : " << a.largestElement2Pointer(arr, size) << "\n";
    a.secondLargestElement(arr, size);
    a.SecondSmallestSecondLargest(arr, size);
    int sortedArr[] = {1, 2, 3, 4, 5, 6};
    int sortedArray[] = {6, 5, 4, 3, 2, 1};
    cout << "\nCheck the array is sorted or nor : " << boolalpha << a.isSorted(sortedArr, 6);
    cout << "\nCheck the array is sorted or nor : " << boolalpha << a.isSortedAscDesc(sortedArray, 6);
    int duplicate[] = {1, 1, 2, 2, 2, 3, 3};
    int k = a.removeDuplicate(duplicate, 7);
    cout << "\nRemove Duplicate From Array : ";
    for (int i = 0; i < k; ++i)
    {
        cout << duplicate[i] << " ";
    }
    cout << "\nLeft Rotate the Array by One : ";
    a.leftRotation(sortedArr, 6);
    for (int i : sortedArr)
    {
        cout << i << " ";
    }
}