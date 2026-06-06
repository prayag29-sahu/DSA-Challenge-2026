#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // unordered_map<string, vector<string>> map;
        // for (string word : strs)
        // {
        //     string shortWord = word;
        //     sort(shortWord.begin(), shortWord.end());
        //     map[shortWord].push_back(word);
        // }
        // vector<vector<string>> ans;

        // for (auto &it : map)
        // {
        //     ans.push_back(it.second);
        // }

        // return ans;

        unordered_map<string, vector<string>> mp;

        for (string word : strs)
        {
            vector<int> freq(26, 0);

            for (char ch : word)
            {
                freq[ch - 'a']++;
            }

            // Create key
            string key = "";

            for (int count : freq)
            {
                key += "#" + to_string(count);
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string>> result = s.groupAnagrams(strs);
    for (auto group : result)
    {
        cout << "[ ";

        for (string word : group)
        {
            cout << word << " ";
        }

        cout << "]\n";
    }

    return 0;
}

// To group anagrams, we need a unique representation for words containing the same character frequencies. Instead of sorting each word, which costs O(k log k), we build a frequency count of 26 lowercase letters and convert it into a unique key. All anagrams generate the same frequency key and are stored together in a hash map. This reduces the overall complexity from O(n × k log k) to O(n × k).