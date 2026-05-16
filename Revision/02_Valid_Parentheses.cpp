#include <iostream>
#include <stack>
using namespace std;

bool valid_parentheses(string str)
{
    int len = str.length();
    stack<char> st;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            if ((str[i] == '}' && st.top() == '{') || (str[i] == ')' && st.top() == '(') || (str[i] == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
}

int main()
{
    string str = "[ Jagrati Nagar { Amkera Gohalpur ( Jabalpur [M.P.] ) } ]";
    cout << boolalpha << valid_parentheses(str);
}