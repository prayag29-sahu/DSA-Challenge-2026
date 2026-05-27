#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute force approach
vector<int> daily_temperature(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (temperatures[j] > temperatures[i])
            {
                res[i] = j - i;
                break;
            }
        }
    }
    return res;
}


// Optimized Approach using stack
vector<int> daily_temperatures(vector<int> &temperature)
{
    int n = temperature.size();
    stack<int> st;
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && temperature[i] > temperature[st.top()])
        {
            int j = st.top();
            st.pop();
            res[j] = i - j;
        }
        st.push(i);
    }
    return res;
}

int main()
{
    vector<int> temperature = {30, 38, 30, 36, 35, 40, 28};
    // vector<int> results = daily_temperature(temperature);
    vector<int> results = daily_temperatures(temperature);
    for (int i : results)
    {
        cout << i << " ";
    }
}