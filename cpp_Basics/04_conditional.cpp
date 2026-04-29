#include <iostream>
using namespace std;

class Solution
{
public:
    // if else case
    char studentGrade(int marks)
    {
        if (marks < 35)
        {
            cout << "Fail";
            return 'F';
        }
        else if (marks < 50)
        {
            cout << "Grade D";
            return 'D';
        }
        else if (marks < 70)
        {
            cout << "Grade C";
            return 'C';
        }
        else if (marks < 90)
        {
            cout << "Grade B";
            return 'B';
        }
        else
        {
            cout << "Grade A";
            return 'A';
        }
    }

    // switch case
    void SwitchStudentGrade(char Grade)
    {
        switch (Grade)
        {
        case 'A':
            cout << "above the 90 marks";
            break;
        case 'B':
            cout << "above the 70 marks";
            break;
        case 'C':
            cout << "above the 50 marks";
            break;
        case 'D':
            cout << "above the 30 marks";
            break;
        case 'F':
            cout << "Fail";
            break;
        default :
            cout << "enter vaid marks. ";
        }
    }
};

int main()
{
    // int x = 0;
    // int y = 4;
    // if(y)
    //     cout << y;
    // if(x)
    //     return 0;

    int marks;
    cout << "Enter the marks : ";
    cin >> marks;
    Solution obj;
    char result = obj.studentGrade(marks);
    cout << "\n";
    obj.SwitchStudentGrade(result);

    return 0;
}