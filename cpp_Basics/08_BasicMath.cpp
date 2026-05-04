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
};

int main()
{
    mathematics m;
    int num = 123;
    // count digits in number
    cout << "Total number of digits in " << num << " is : " << m.countDigits(num) << "\n";
    cout << "The reverse of Number " << num << " is : " << m.reverseNumber(num) << "\n";
}