#include <iostream>
#include <math.h>
using namespace std;

class mathematics
{
public:
    // count total number of digits
    int countDigits(int n)
    {
        // brute force approach
        // int count = 0;
        // while(n>0){
        //     n /= 10;
        //     ++count;
        // }
        // return count;

        // optimized approach
        return (int)(log10(n) + 1);
    }

    // reverse the number
    int reverseNumber(int n)
    {
        int reverse = 0;
        while (n > 0)
        {
            reverse = (reverse * 10) + n % 10;
            n /= 10;
        }
        return reverse;
    }

    // Palindrom check
    bool isPalindrome(int n)
    {
        int palind = 0;
        int temp = n;
        while (temp > 0)
        {
            palind = (palind * 10) + temp % 10;
            temp /= 10;
        }
        if (n == palind)
            return true;
        else
            return false;
    }

    // GCD calculation
    int GCD(int n1, int n2)
    {
        int min = n1 < n2 ? n1 : n2;
        int gcd = 1;
        for (int i = 2; i < min; ++i)
        {
            if ((n1 % i == 0) && (n2 % i == 0))
            {
                gcd = i;
            }
        }
        return gcd;
    }
};

int main()
{
    mathematics m;
    int num = 123;
    int n1 = 15, n2 = 18;
    // count digits in number
    cout << "Total number of digits in " << num << " is : " << m.countDigits(num) << "\n";
    cout << "The reverse of Number " << num << " is : " << m.reverseNumber(num) << "\n";
    cout << "Check the palindrom for " << num << " is : " << m.isPalindrome(12321) << "\n";
    cout << "GCD of  " << n1 << " and " << n2 << " is : " << m.GCD(n1, n2) << "\n";
}