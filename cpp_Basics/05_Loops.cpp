#include<iostream>
#include<vector>
using namespace std;

int main(){

    // for loop
    for (int i = 0; i < 5; ++i){
        cout << i << "\t";
    }
    cout << "\n";

    // while loop
    int i=0;
    // while(i<10){
    //     cout << i << "\t";
    //     ++i;
    // }

    // do while loop
    do{
        cout << i << "\t";
        ++i;
    } while (i < 5);

    cout << "\n";

    // for each 
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    for(int x:arr){
        cout << x << "\t";
    }

    cout << "\n";
    // nested loop
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "i = " << i << ", j = " << j << "\t";
        }
    }
    return 0;
}