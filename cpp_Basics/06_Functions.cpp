#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// pass by value
void passByValue(int a)
{
    a += 5;
}

// Pass by reference
void passByReference(int &a)
{
    a += 5;
}

// print reverse of array using pass by refrence
void arrayReverse(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        // int temp = arr[left];
        // arr[left] = arr[right];
        // arr[right] = temp;
        swap(arr[left], arr[right]);
        ++left;
        --right;
    }
}

// count frequency of array elements
void frequencyCount(vector<int> &arr, unordered_map<int, int> &map)
{
    for(int x:arr){
        map[x]++;
    }
}

// swap 2 elements using refrences 
void swapElements(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5;
    // pass by value
    passByValue(x);
    cout << x << "\n";

    // Pass by reference
    passByReference(x);
    cout << x << "\n";

    // print reverse of array using pass by refrence
    vector<int> arr = {1, 2, 3, 4, 2, 3, 4, 6, 3, 5};
    arrayReverse(arr);
    for (int x : arr)
    {
        cout << x << "\t";
    }

    // count frequency of array elements
    unordered_map<int, int> map;
    frequencyCount(arr, map);
    for (auto it : map)
    {
        cout << "\n" << it.first << " -> " << it.second;
    }

    // swap 2 elements using refrences
    int a = 10, b = 20;
    cout << "\nBefore Swap a = "<< a << " b = " << b;
    swapElements(a, b);
    cout << "\nAfter Swap a = " << a << " b = " << b;
}