#include<iostream>
using namespace std;

bool isPlaindrome(string str){
    int n = str.size();
    int left = 0;
    int right = n - 1;
    while(left<right){
        if(left<right && !isalnum(str[left])){
            ++left;
        }
        if(left<right && !isalnum(str[right])){
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
    string str = "Was it a car or a cat I saw?";
    cout << boolalpha << isPlaindrome(str);
}