#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> Two_Sum(vector<int>& nums, int target){
    unordered_map<int, int> val;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        int complement = target - nums[i];
        if (val.find(complement) != val.end()){ // val.find(complement) find krega ki map me complement value ha ki nhi agr ha to vo val.end() ke sath match nhi hoga and true return krega else false , the alternate approch we can use val.cou t(complement) this directly return true and false but not provide value which was not needed here 
            return {val[complement], i};
        }
        val[nums[i]] = i; // here we add the val and index on map val, in this method if the value already exist it override/update the value and index, we also have an alternate method val.insert({nums[i], i}); in this case if the value already have it skip the insertion so its not flexible.  
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