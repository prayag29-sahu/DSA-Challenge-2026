#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool permutation_in_string(string s1, string s2)
    {
        int n = s1.length();
        int m = s2.length();
        if (n > m)
        {
            return false;
        }
        vector<int> frq1(26, 0);
        vector<int> frq2(26, 0);
        for (char c : s1)
        {
            frq1[c - 'a']++;
        }
        int left = 0;
        for (int right = 0; right < n; ++right)
        {
            frq2[s2[right] - 'a']++;
        }
        if (frq1 == frq2)
        {
            return true;
        }
        for (int right = n; right < m; ++right)
        {
            frq2[s2[right] - 'a']++;
            frq2[s2[right-n] - 'a']--;
            if(frq1 == frq2)
                return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << boolalpha << s.permutation_in_string(s1, s2);

}