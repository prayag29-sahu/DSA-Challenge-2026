#include <iostream>
#include <stack>
using namespace std;

bool Valid_parenthese(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else if (c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "({[]})";
    cout << boolalpha << Valid_parenthese(s);
}
