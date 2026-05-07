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
        unordered_map<string, vector<string>> map;
        for (string word : strs)
        {
            string shortWord = word;
            sort(shortWord.begin(), shortWord.end());
            map[shortWord].push_back(word);
        }
        vector<vector<string>> ans;

        for (auto &it : map)
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