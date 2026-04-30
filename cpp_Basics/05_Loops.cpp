#include<iostream>
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
}