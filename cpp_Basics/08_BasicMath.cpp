#include<iostream>
#include<math.h>
using namespace std;

class mathematics{
    public :
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
};


int main(){
    mathematics m;
    int num = 123;
    // count digits in number
    cout << "Total number of digits in " << num << " is : " << m.countDigits(num);
}