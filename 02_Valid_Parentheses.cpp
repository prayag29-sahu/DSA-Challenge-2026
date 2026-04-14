#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool valid_parentheses(string s)
{
    stack<char> st;
    unordered_map<char, char> match = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || st.top() != match[c])
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    cout << boolalpha;
    bool result = valid_parentheses("()");
    cout << result << endl;
}