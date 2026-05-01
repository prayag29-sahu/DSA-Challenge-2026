#include<iostream>
using namespace std;

// pass by value 
void passByValue(int a){
    a += 5;
}


int main(){
    int x = 5;
    // pass by value
    passByValue(x);
    cout << x<<"\n";


}