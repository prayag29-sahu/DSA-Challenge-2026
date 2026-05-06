#include <iostream>
using namespace std;

class Recursion
{
public:
    // print n time name
    int name_Print(int n, string name)
    {
        if (n == 0)
            return 0;
        cout << name << " ";
        name_Print(n - 1, name);
    }

    // print 1 to n using recursion
    int print_N_Numbers(int i,int n){
        if(i>n)
            return 0;
        cout << i << " ";
        print_N_Numbers(++i,n);
    }
};
int main()
{
    // print n time name
    Recursion r;
    // int n;
    // string name;
    // cout << "Enter a number to print name : ";
    // cin >> n;
    // cout << "Enter a name to print : ";
    // cin >> name;
    // r.name_Print(n, name);
    cout << "Print n time name : ";
    r.name_Print(5, "Prayag");

    // print 1 to n using recursion
    cout << "\nPrint 1 to n digits : ";
    r.print_N_Numbers(1,5);
}