#include <iostream>
#include <math.h>
#include <vector>
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

    // Palindrom check for digits/numbers
    bool isPalindromeForDigits(int n)
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
    // Palindrom check for string
    bool isPalindromeForString(string s, int i)
    {
        int left = i;
        int right = s.length() - 1;
        while (left < right)
        {
            if (!isalnum(s[left]))
                ++left;
            else if (!isalnum(s[right]))
                --right;
            else if(tolower(s[left])!=tolower(s[right])) {
                return false;
            } else {
                ++left;
                --right;
            }   
        }
        return true;
    }

    // GCD calculation
    int GCD(int n1, int n2)
    {
        // Normal approach
        // int min = n1 < n2 ? n1 : n2;
        // int gcd = 1;
        // for (int i = 2; i < min; ++i)
        // {
        //     if ((n1 % i == 0) && (n2 % i == 0))
        //     {
        //         gcd = i;
        //     }
        // }
        // return gcd;

        // Optimized approach
        while (n1 > 0 && n2 > 0)
        {
            if (n1 > n2)
            {
                n1 = n1 % n2;
            }
            else
            {
                n2 = n2 % n1;
            }
        }
        if (n1 == 0)
        {
            return n2;
        }
        return n1;
    }

    // Armstrong number 153 = 1^3+5^3+3^3 = 153 ?
    bool isArmstrong(int a)
    {
        int n = a;
        int p = (int)(log10(a) + 1);
        int arm = 0;
        while (n > 0)
        {
            int rem = n % 10;
            int pow = 1;
            for (int i = 0; i < p; i++)
            {
                pow *= rem;
            }
            arm += pow;
            n /= 10;
        }
        if (arm == a)
        {
            return true;
        }
        return false;
    }

    // Divisor printing
    vector<int> divisors(int n) // 6
    {
        vector<int> ans;
        for (int i = 1; i * i < n + 1; ++i) // i=1 , 2
        {
            if (n % i == 0)
            {
                ans.push_back(i); // 1,2
            }
            if (i != n / i)
            {
                ans.push_back(n / i); // 6,3
            }
        }
        return ans;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    mathematics m;
    int num = 153;
    int n = 12321;
    int n1 = 15, n2 = 18;
    string str1 = "hii my name is prayag";
    string str = " A man, a plan, a canal : Panama ";
    cout << boolalpha;
    // count digits in number
    cout << "Total number of digits in " << num << " is : " << m.countDigits(num) << "\n";
    cout << "The reverse of Number " << num << " is : " << m.reverseNumber(num) << "\n";
    cout << "Check the palindrom for number" << n << " is : " << m.isPalindromeForDigits(n) << "\n";
    cout << "Check the palindrom for string " << str << " is : " << m.isPalindromeForString(str, 0) << "\n";
    cout << "GCD of  " << n1 << " and " << n2 << " is : " << m.GCD(n1, n2) << "\n";
    // lcm of a,b  = a*b/gcd of a,b
    cout << "LCM of  " << n1 << " and " << n2 << " is : " << (n1 * n2) / m.GCD(n1, n2) << "\n";
    cout << "Check number : " << num << " is Armstrong : " << m.isArmstrong(num) << "\n";
    vector<int> res = m.divisors(6);
    cout << "divisors of 6 : ";
    for (int n : res)
        cout << n << " ";
    cout << "\n";
    int number = 47;
    cout << "Chcek Prime" << number << " : " << m.isPrime(number) << "\n";
}