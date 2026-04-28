#include <iostream>
using namespace std;

class Solution
{
public:
    void studentGrade(int marks)
    {
        if (marks < 35)
        {
            cout << "Fail";
        }
        else if (marks < 50)
        {
            cout << "Grade D";
        }
        else if (marks < 70)
        {
            cout << "Grade C";
        }
        else if (marks < 90)
        {
            cout << "Grade B";
        }
        else
        {
            cout << "Grade A";
        }
    }
};

int main()
{
    int x = 0;
    int y = 4;

    Solution obj;

    obj.studentGrade(55);

    // if(y)
    //     cout << y;
    // if(x)
    //     return 0;
    return 0;
}