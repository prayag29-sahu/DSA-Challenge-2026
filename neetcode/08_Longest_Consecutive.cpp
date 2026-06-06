#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int LongestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    unordered_set<int> set(nums.begin(), nums.end());
    int length = 0;
    for(int num :set){
        if(set.find(num-1)==set.end()){
            int currVal = num;
            int currLenght = 1;
            while(set.find(currVal+1)!=set.end()){
                currVal++;
                currLenght++;
            }
            length = max(length, currLenght);
        }
    }
    return length;
}

int main()
{
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    cout <<"Longest Consecutive is : " << LongestConsecutive(nums) << endl;
}

// TC: O(n)
// SC: O(n)
//
// Store all elements in a hash set for O(1) lookup.
// Only start expanding a sequence if the current number
// is the beginning of that sequence (num-1 does not exist).
// This prevents repeated work and ensures every element
// is visited at most once.