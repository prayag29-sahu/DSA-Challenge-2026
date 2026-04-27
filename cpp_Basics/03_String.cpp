#include <bits/stdc++.h>
using namespace std;

// Class containing the method to find string length
class Solution
{
public:
    // Function to return length of a string
    int findLength(string s)
    {
        // Return length using built-in function
        return s.length();
    }
    // Function to print each character of a string
    void accessCharacters(string s)
    {
        // Loop through each index
        for (int i = 0; i < s.length(); i++)
        {
            // Print the character at index i
            cout << s[i] << "\t";
        }
    }
    // Function to modify the string
    string modifyString(string str)
    {
        // Assign str to a new variable
        string newStr = str;

        // Modify the new string
        newStr[0] = 'H';

        // Return the modified string
        return newStr;
    }
};

// Driver code
int main()
{
    // Create object of Solution class
    Solution obj;
    // Input string
    string s = "Hello World";
    // Call function and print result
    cout << obj.findLength(s) << endl;
    obj.accessCharacters(s);

    // Call modifyString and store the result
    string modified = obj.modifyString(s);

    // Print both strings
    cout << "Original String: " << s << endl;
    cout << "Modified String: " << modified << endl;

    return 0;
}
