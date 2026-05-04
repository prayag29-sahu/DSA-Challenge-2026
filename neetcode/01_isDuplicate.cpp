#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class IsDuplicate{
    public:
    bool isDuplicate(vector<int> &nums){
        unordered_map<int, int> m;
        for(int n: nums){
            if(m.find(n)!=m.end()){
                return true;
            }
            m[n]++;
        }
        return false;
    }
};

int main(){
    IsDuplicate d;
    vector<int> nums = {1, 2, 4, 3, 5, 2, 8};
    // vector<int> nums = {1, 2, 4, 3, 5, 8};
    bool r = static_cast<bool>(d.isDuplicate(nums));
    cout<< boolalpha << r;
}