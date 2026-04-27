#include <bits/stdc++.h>
using namespace std;

// Class containing the method to find string length
class Solution {
public:
    // Function to return length of a string
    int findLength(string s) {
        // Return length using built-in function
        return s.length();
    }
};

// Driver code
int main() {
    // Create object of Solution class
    Solution obj;
    // Input string
    string s = "Hello World";
    // Call function and print result
    cout << obj.findLength(s) << endl;
    return 0;
}
