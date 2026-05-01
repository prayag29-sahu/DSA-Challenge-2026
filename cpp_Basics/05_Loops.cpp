#include <iostream>
#include <vector>
using namespace std;

/*
Given two integers low and high, return the sum of all integers from low to high inclusive.


Example 1

Input: low = 1, high = 5

Output: 15

Explanation: 1 + 2 + 3 + 4 + 5 = 15

Example 2

Input: low = 3, high = 7

Output: 25

Explanation: 3 + 4 + 5 + 6 + 7 = 25
*/
class Solution
{
public:
    int forLoop(int low, int high)
    {
        int sum = 0;
        for (int i = low; i <= high; ++i)
        {
            sum += i;
        }
        return sum;
    }

    int factorial(int num)
    {
        int factorial = 1;

        while (num > 0)
        {
            factorial *= num;
            num--;
        }

        cout << "Factorial is: " << factorial << endl;
    }

    /*
    Given a digit d (0 to 9), find the sum of the first 50 positive integers (integers > 0) that end with digit d.

A number ends with digit d if its last digit is d.

Example 1

Input: d = 1

Output: 12300

Explanation:

The first 50 positive integers ending with 1 are: 1, 11, 21, 31, ..., 491

Their sum is 12300.
    */
    int whileLoop(int d)
    {
        int val = d;
        int sum = d;
        int i = 0;
        while (i < 49)
        {
            val += 10;
            sum += val;
            i++;
        }
        return sum;
    }
};

int main()
{

    // for loop
    for (int i = 0; i < 5; ++i)
    {
        cout << i << "\t";
    }
    cout << "\n";

    // while loop
    int i = 0;
    // while(i<10){
    //     cout << i << "\t";
    //     ++i;
    // }

    // do while loop
    do
    {
        cout << i << "\t";
        ++i;
    } while (i < 5);

    cout << "\n";

    // for each
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    for (int x : arr)
    {
        cout << x << "\t";
    }

    cout << "\n";
    // nested loop
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "i = " << i << ", j = " << j << "\t";
        }
    }

    // create object of class solution
    Solution s;

    // for loop application
    cout << "\nsum is : " << s.forLoop(1, 5);

    // while loop application
    cout << "\n";
    s.factorial(5);

    // end digit val sum 
    cout << "\n"
         << s.whileLoop(1);

    return 0;
}
