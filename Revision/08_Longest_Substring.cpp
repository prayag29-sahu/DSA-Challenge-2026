#include <iostream>
#include<vector>
using namespace std;

int longest_substring(string str)
{
    vector<int> s(128, -1);
    int left = 0;
    int maxSubstring = 0;
    for (int right = 0; right < str.size(); ++right)
    {
        if(s[str[right]]>=left){
            left = s[str[right]] + 1;
        }
        s[str[right]] = right;
        maxSubstring = max(maxSubstring, right - left + 1);
    }
    return maxSubstring;
}

int main()
{
    cout << longest_substring("abcedab cdefab");  // o/p 7 count space also
}