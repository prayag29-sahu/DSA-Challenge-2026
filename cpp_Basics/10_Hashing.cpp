#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Hashing{
    public:
    vector<vector<int>> frequencyCount(vector<int> &nums){
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size();++i){
            freq[nums[i]]++;
        }
        vector < vector<int>> res;
        for(auto &it:freq){
            res.push_back({it.first, it.second});
        }
        return res;
    }
};
int main(){
    Hashing h;
    vector<int> nums = {1, 2, 2, 1, 3};
    vector<vector<int>> ans;
    ans = h.frequencyCount(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " -> " << ans[i][1] << endl;
    }
}