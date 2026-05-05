#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class IsAnagram{
    public:
    bool isAnagram(string s, string t){
        if(s.size()!=t.size())
            return false;
        vector<int> v(26,0);
        for(char c:s)
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
};

int main(){
    IsAnagram a;
    bool ans = a.isAnagram("abcde", "decba");
    cout << boolalpha;
    cout << ans;
}