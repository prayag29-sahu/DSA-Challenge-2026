#include<iostream>
#include<vector>
using namespace std;

bool valid_anagram(string str1, string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    vector<int> seen(26,0);
    int n = str1.size();
    for (int c = 0; c < n;++c){
        seen[str1[c]-'a']++;
        seen[str2[c]-'a']--;
    }
    for(int c:seen){
        if(c!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string str1 = "anagram";
    string str2 = "margana";
    cout<< boolalpha<<valid_anagram(str1, str2);
}