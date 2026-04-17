#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int Longest_Substring(string s){
    int size = s.size();
    unordered_map<char, int> str;
    int left = 0;
    int Max_Lenght = 0;

    for (int right = 0; right < size; right++){
        if(str.count(s[right]) && str[s[right]]>= left){
            left = str[s[right]] + 1;
        }
        str[s[right]] = right;
        Max_Lenght = max(Max_Lenght, right - left + 1);
    }
    return Max_Lenght;
}

int main(){
    cout << Longest_Substring("abcabcaab");
    return 0;
}