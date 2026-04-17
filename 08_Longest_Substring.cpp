#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// using hashmap time O(n) and space O(n)
// int Longest_Substring(string s){
//     int size = s.size();
//     unordered_map<char, int> str;
//     int left = 0;
//     int Max_Lenght = 0;

//     for (int right = 0; right < size; right++){
//         if(str.count(s[right]) && str[s[right]]>= left){
//             left = str[s[right]] + 1;
//         }
//         str[s[right]] = right;
//         Max_Lenght = max(Max_Lenght, right - left + 1);
//     }
//     return Max_Lenght;
// }

// using hash set  time O(n) and space O(n)
// int Longest_Substring(string s){
//     int size = s.size();
//     unordered_set<char> str;
//     int left = 0;
//     int Max_Lenght = 0;

//     for (int right = 0; right < size; right++){
//         while(str.count(s[right])){
//             str.erase(s[left++]);
//         }
//         // str[s[right]] = right;
//         str.insert(s[right]);
//         Max_Lenght = max(Max_Lenght, right - left + 1);
//     }
//     return Max_Lenght;
// }

// using vector array time O(n) and space O(1)
int Longest_Substring(string s)
{
    int size = s.size();
    vector<int> str(128, -1);
    int left = 0;
    int Max_Lenght = 0;

    for (int right = 0; right < size; right++)
    {
        if (str[s[right]] >= left)
        {
            left = str[s[right]] +1;
        }
        str[s[right]] = right;
        Max_Lenght = max(Max_Lenght, right - left + 1);
    }
    return Max_Lenght;
}

int main()
{
    cout << Longest_Substring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    return 0;
}