#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
        {
            return "";
        }
        auto &vec = mp[key];
        int left = 0;
        int right = vec.size() - 1;
        string ans = "";
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp)
            {
                ans = vec[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    TimeMap timeMap;
    timeMap.set("alice", "happy", 1);
    cout << timeMap.get("alice", 1) << endl;
    cout << timeMap.get("alice", 2) << endl;
    timeMap.set("alice", "sad", 3);
    cout << timeMap.get("alice", 3) << endl;

    return 0;
}