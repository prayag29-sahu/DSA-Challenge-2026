#include<iostream>
#include<stack>
#include <climits>

using namespace std;

// // my 1st approach
// class MinStack {
// private:
//     stack<int> st;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//        return st.top();
//     }
    
//     int getMin() {
//         stack<int> temp = st;
//         int min_val = INT_MAX;
//         while(!temp.empty()){
//             min_val = min(min_val, temp.top());
//             temp.pop();
//         }
//         return min_val;
//     }
// };

// 2 stack
class MinStack
{
private:
    stack<int> st;

    stack<int> minst;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);

        if(minst.empty()|| val<minst.top()){
            minst.push(val);
        }
    }

    void pop()
    {
        if(st.top()==minst.top()){
            minst.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minst.top();
    }
};


int main(){
    MinStack minStack;
    minStack.push(-2);                
    minStack.push(0);                 
    minStack.push(-3);                
    cout << minStack.getMin() << "\n"; 
    minStack.pop();                    
    cout << minStack.top() << "\n";    
    cout << minStack.getMin() << "\n"; 
    return 0;
}