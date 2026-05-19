#include<iostream>
using namespace std;

bool isPalindrome(string str){
    int n = str.size();
    int left = 0;
    int right = n - 1;
    while(left<right){
        while(left<right && !isalnum(str[left])){
            ++left;
        }
        while(left<right && !isalnum(str[right])){
            --right;
        }
        if(tolower(str[left])!=tolower(str[right])){
            return false;
        }

        ++left;
        --right;
    }
    return true;
}


int main(){
    string str = "Madam, in Eden, I'm Adam";
    cout << boolalpha << isPalindrome(str);
}