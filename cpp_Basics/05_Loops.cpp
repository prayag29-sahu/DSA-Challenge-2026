#include<iostream>
#include<vector>
using namespace std;

int main(){

    // for loop
    for (int i = 0; i < 5; ++i){
        cout << i << "\t";
    }
    cout << endl;

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
    cout << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    for(int x:arr){
        cout << x << "\t";
    }
}