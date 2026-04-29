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
        default:
            cout << "enter vaid marks. ";
        }
    }

    void SwitchEvaluation(int x, int y)
    {
        // Evaluate the sum of x and y using a switch statement
        switch (x + y)
        {
        case 15: // If the sum equals 15
            cout << "Result is 15." << endl;
            break; // Exit the switch block
        case 20:   // If the sum equals 20
            cout << "Result is 20." << endl;
            break; // Exit the switch block
        default:   // If no case matches
            cout << "No match found." << endl;
        }
    }
};

int main()
{
    int x = 10;
    int y = 10;
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
    cout << "\n";
    obj.SwitchEvaluation(x, y);

    return 0;
}