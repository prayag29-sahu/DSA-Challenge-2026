#include <iostream>
#include <vector>
using namespace std;

bool is_valid_anagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    // vector<int> freq = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0};
    vector<int> freq(26,0);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        // cout << freq[s[i] - 'a']++ << endl;
        // cout << freq[t[i] - 'a']-- << endl;
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int count : freq)
    {
        if (count != 0)
            return false;
    }
    return true;
}

int main()
{
    cout << boolalpha;
    cout << is_valid_anagram("anagram", "margana");
    return 0;
}