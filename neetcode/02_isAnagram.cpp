#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class IsAnagram
{
public:
    // used when talk about only small alphabets
    // TC O(n) : O(n)+O(n)+O(n) for 3 loop total O(n)
    // SC O(1) : O(26) for constant elements 
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> v(26, 0); // allocate 26 space and assign 0 in all form 0 to 25
        // We count character frequencies from the first string
        // and subtract frequencies using the second string.
        for (char c : s)
            v[c - 'a']++;
        for (char c : t)
            v[c - 'a']--;

        for (int x : v)
        {
            if (x != 0)
                return false;
        }

        return true;
    }

    // used when mixed small , capital, alphanumeric, symobls
    // TC O(n) : O(n)+O(n)+O(n) for 3 loop total O(n)
    // SC O(k) : O(k) for k unique char in map
    bool isUniverseAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, int> str;
        for (char c : s)
        {
            str[c]++;
        }
        for (char c : t)
        {
            str[c]--;
        }
        for (auto it : str)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }

    // Whem use sorting
    // TC O(n log n) : O(n log n)+O(n log n) for 2 time sorting total O(n log n)
    // SC O(1) : O(26) for constant elements
    bool isSortAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main()
{
    IsAnagram a;
    // bool ans = a.isAnagram("abcde", "decba");
    // bool ans = a.isUniverseAnagram("abcde", "decba");
    bool ans = a.isSortAnagram("abcde", "decba");
    cout << boolalpha << ans;
}

// TC: O(n)
// SC: O(1)
// We count character frequencies from the first string
// and subtract frequencies using the second string.
// Since the frequency array size is fixed (26 lowercase letters),
// extra space remains constant.