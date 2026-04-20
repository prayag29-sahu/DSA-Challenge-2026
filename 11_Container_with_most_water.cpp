#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int most_water(vector<int> & height){
    int left = 0;
    int right = height.size()-1;
    int area = 0;

    while(left<right){
        area = max(area, (right - left) * min(height[left], height[right]));
        if(height[left]<height[right]){
            ++left;
        } else {
            --right;
        }
    }
    return area;
}

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << most_water(height);
}