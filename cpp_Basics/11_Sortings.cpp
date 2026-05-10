#include <iostream>
using namespace std;

class sorting
{
public:
    void selection_sort(int num[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            int min = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (num[j] <= num[min])
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
            for (int j = 0; j < n - i; ++j)
            {
                if (num[j] > num[j + 1])
                {
                    swap(num[j], num[j + 1]);
                }
            }
        }
    }
};

int main()
{
    sorting s;
    int arr[] = {5, 2, 4, 1, 7, 5, 10, 3, 43, 12, 65, 0, 34, -1};
    int n = 14;
    // s.selection_sort(arr, n);
    s.bubble_sort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}