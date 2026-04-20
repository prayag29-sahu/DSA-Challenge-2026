#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> Two_Sum(vector<int>& nums, int target){
    unordered_map<int, int> val;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        int complement = target - nums[i];
        if (val.find(complement) != val.end()){ 
            return {val[complement], i};
        }
        val[nums[i]] = i; 
    }
    return {};
}


int main(){
    vector<int> nums = {2, 9, 7, 11};
    int target = 9;
    vector<int> results = Two_Sum(nums, target);
    cout << results[0] << " " << results[1] << endl;
    return 0;
}