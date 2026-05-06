#include <iostream>
using namespace std;

class Recursion
{
public:
    // print n time name
    void name_Print(int n, string name)
    {
        if (n == 0)
            return ;
        cout << name << " ";
        name_Print(n - 1, name);
    }

    // print 1 to n using recursion
    void print_N_Numbers(int i,int n){
        if(i>n)
            return ;
        cout << i << " ";
        print_N_Numbers(++i,n);
    }

    // print 1 to n using recursion Backtractig
    void print_N_Numbers2(int n)
    {
        if (n ==0)
            return ;
        print_N_Numbers2(n-1);
        cout << n << " ";
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

    // print 1 to n using recursion backtraking 
    cout << "\nPrint 1 to n digits using Backtracking : ";
    r.print_N_Numbers2(5);
}