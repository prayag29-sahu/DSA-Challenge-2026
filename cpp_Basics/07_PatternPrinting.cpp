#include <iostream>
#include <string>
using namespace std;

class pattern
{
public:
    void square(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << "* ";
            }
            cout << "\n";
        }
    }
    void leftLowerTriangle(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i + 1; ++j)
            {
                cout << "* ";
            }
            cout << "\n";
        }
    }
    void leftUpperTriangle(int n)
    {
        for (int i = n; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                cout << "* ";
            }
            cout << "\n";
        }
    }
    void rightLowerTriangle(int n)
    {
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = n; j > i+1; --j)
        //     {
        //         cout << " ";
        //     }
        //     for (int k = 0; k < i+1; ++k)
        //     {
        //         cout << "*";
        //     }
        //     cout << "\n";
        // }

        // alternate method both take O(n^2)
        for (int i = 1; i <= n; ++i)
        {
            cout << string(n - i, ' ') << string(i, '*') << "\n";
        }
    }
    void rightUpperTriangle(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = n; j > i; --j)
            {
                cout << "*";
            }
            for (int k = 0; k < i; ++k)
            {
                cout << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    pattern p;
    cout << "Square :" << endl;
    p.square(4);
    cout << "Left Lower Traingle :" << endl;
    p.leftLowerTriangle(4);
    cout << "Left Upper Traingle :" << endl;
    p.leftUpperTriangle(4);
    cout << "Right Lower Traingle :" << endl;
    p.rightLowerTriangle(4);
    cout << "Right Upper Traingle :" << endl;
    p.rightUpperTriangle(4);
    return 0;
}