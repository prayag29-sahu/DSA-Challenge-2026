#include <iostream>
#include<vector>
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
void arrayReverse(vector<int> &arr){
    int left = 0;
    int right = arr.size() - 1;
    while(left<right){
        // int temp = arr[left];
        // arr[left] = arr[right];
        // arr[right] = temp;
        swap(arr[left], arr[right]);
        ++left;
        --right;
    }
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
    vector<int> arr = {1, 2, 3, 4, 5};
    arrayReverse(arr);
    for(int x:arr){
        cout << x << "\t";
    }
}