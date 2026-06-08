#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int longest_substring(string s){
        int n = s.length();
        int left = 0;
        int maxlen = 0;
        vector<int> v(128, -1);
        for (int right = 0; right < n;++right){
            if(v[s[right]]>=left){
                left = v[s[right]] + 1;
            }
            v[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};

int main(){
    Solution obj;
    string s = "abcabcda";
    cout << "Longest substring lenght : " << obj.longest_substring(s);
}