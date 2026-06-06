#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class IsDuplicate
{
public:
    bool isDuplicate(vector<int> &nums)
    {
        unordered_set<int> m; //  unordered set<value>
        // unordered_map<int, int> m; // unordered map<key,value> alternate can use this
        for (int n : nums)
        {
            if (m.find(n) != m.end())
            // m.find(n) returns an iterator to the element if key n exists, otherwise it returns m.end() and can store in auto it = m.find(n) and access usng it->first {print key} and it->second {print value}
            // m.end() returns an iterator representing the position just after the last element of the map and is commonly used to indicate "not found" when comparing with find()
            {
                return true;
            }
            // m[n]++; // Increase frequency/count of key n by 1. If key doesn't exist, create it with value 0 first, then increment to 1. here n is a key and we increment the value by 1 , mostly use in frequency questions and has propety of unordered map
            m.insert(n);
        }
        return false;
    }
};

int main()
{
    IsDuplicate d;
    vector<int> nums = {1, 2, 4, 3, 5, 2, 8};
    // vector<int> nums = {1, 2, 4, 3, 5, 8};
    cout << boolalpha << d.isDuplicate(nums);
}

// TC: O(n)  |  SC: O(n)
// O(n) time for single traversal, O(n) space for storing up to n unique keys in the hashmap.

// alternate method sorting - sort the array and find next element is same as present is its true return true
// TC: O(n log n) | SC: O(1)
// Sorting takes O(n log n) time.
// After sorting, one linear pass checks adjacent elements in O(n) time.
// Total time complexity = O(n log n) + O(n) =  O(n log n).
// No extra data structure is used, so auxiliary space = O(1).

// Since only membership checking is required and frequencies are not used, unordered_set is a cleaner choice than unordered_map. Both provide average O(1) lookup and insertion, giving an overall O(n) time complexity and O(n) space complexity.