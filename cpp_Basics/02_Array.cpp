#include <iostream>
using namespace std;

class MyArray
{
public:
    int my_index(int arr[], int i)
    {
        return arr[i];
    }
};

int main()
{
    MyArray obj;
    int arr[] = {1, 2, 3, 4, 5};
    // int arr1[10];
    int a;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Enert an index value to find element (index value should be < " << n << " ) : ";
    cin >> a;
    if (a >= 0 && a < n)
    {
        cout << a << " index value in array : " << obj.my_index(arr, a);
    }
    else
    {
        cout << "Invalid index";
    }

    return 0;
}