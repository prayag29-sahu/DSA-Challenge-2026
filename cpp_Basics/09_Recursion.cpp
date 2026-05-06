#include <iostream>
using namespace std;

class Recursion
{
public:
    int namePrint(int n, string name)
    {
        if (n == 0)
            return 0;
        cout << name << " ";
        namePrint(n - 1, name);
    }
};
int main()
{
    // print n time name
    Recursion r;
    int n;
    string name;
    cout << "Enter a number to print name : ";
    cin >> n;
    cout << "Enter a name to print : ";
    cin >> name;
    // r.namePrint(n, name);
    r.namePrint(5, "Prayag");
}