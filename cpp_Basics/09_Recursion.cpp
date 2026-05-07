#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Recursion
{
public:
    // print n time name
    void name_Print(int n, string name)
    {
        if (n == 0)
            return;
        cout << name << " ";
        name_Print(n - 1, name);
    }

    // print 1 to n using recursion
    void print_N_Numbers(int i, int n)
    {
        if (i > n)
            return;
        cout << i << " ";
        print_N_Numbers(++i, n);
    }

    // print 1 to n using recursion Backtractig
    void print_N_Numbers2(int n)
    {
        if (n == 0)
            return;
        print_N_Numbers2(n - 1);
        cout << n << " ";
    }

    // sum of first n number
    int sum_of_N_numbers(int n)
    {
        if (n == 1)
            return 1;
        n += sum_of_N_numbers(n - 1);

        return n;
    }

    // without recursion but best approach direct use formula
    int sum_of_N_numbers1(int n)
    {
        return n * (n + 1) / 2;
    }

    // factorial of first n number
    int factorial_of_N_numbers(int n)
    {
        if (n == 1)
            return 1;
        n *= factorial_of_N_numbers(n - 1);

        return n;
    }

    // reverse array using recursion
    vector<int> reverse_Array(vector<int> &arr, int left, int right)
    {
        if (left >= right)
            return arr;
        swap(arr[left], arr[right]);
        reverse_Array(arr, left + 1, right - 1);

        return arr;
    }

    // check string palinderom using recursion
    bool isPalindrome(string &s, int left, int right)
    {
        if (left >= right)
            return true;
        if (s[left] != s[right])
            return false;

        return isPalindrome(s, left + 1, right - 1);
    }

    // print fibonacci series
    int fibonacci(int n)
    {
        if (n <= 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};
int main()
{
    // print n time name
    Recursion r;
    // int n;
    // string name;
    // cout << "Enter a number to print name : ";
    // cin >> n;
    // cout << "Enter a name to print : ";
    // cin >> name;
    // r.name_Print(n, name);
    cout << "Print n time name : ";
    r.name_Print(5, "Prayag");

    // print 1 to n using recursion
    cout << "\nPrint 1 to n digits : ";
    r.print_N_Numbers(1, 5);

    // print 1 to n using recursion backtraking
    cout << "\nPrint 1 to n digits using Backtracking : ";
    r.print_N_Numbers2(5);

    // print 1 to n sum using recursion
    int sum = r.sum_of_N_numbers(10);
    cout << "\nPrint 1 to n sum digits : " << sum;

    // without recursion but best approach
    int sum1 = r.sum_of_N_numbers1(10);
    cout << "\nPrint 1 to n sum digits without recursion but best approach Direct use formual : " << sum1;

    // print fectorial of n using recursion
    int fact = r.factorial_of_N_numbers(5);
    cout << "\nPrint 1 to n sum digits : " << fact;

    // reverse an array and print
    vector<int> arr = {1, 2, 3, 4, 5};
    r.reverse_Array(arr, 0, arr.size() - 1);
    cout << "\nPrint the array in reverse order : ";
    for (int n : arr)
    {
        cout << n << " ";
    }

    // check the string is palindrome or not using recursion
    string str = "abbba";
    cout << boolalpha << "\nstring " << str << " is palinerome ? : " << r.isPalindrome(str, 0, str.length() - 1);

    // print fibonacci series
    cout << endl;
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << r.fibonacci(i) << " ";
    }

    return 0;
}