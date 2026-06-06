#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class IsAnagram
{
public:
    // used when talk about only small alphabets
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> v(26, 0);
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
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }

};

int main()
{
    IsAnagram a;
    // bool ans = a.isAnagram("abcde", "decba");
    bool ans = a.isUniverseAnagram("abcde", "decba");
    cout << boolalpha << ans;
}

// TC: O(n)
// SC: O(1)
// We count character frequencies from the first string
// and subtract frequencies using the second string.
// Since the frequency array size is fixed (26 lowercase letters),
// extra space remains constant.