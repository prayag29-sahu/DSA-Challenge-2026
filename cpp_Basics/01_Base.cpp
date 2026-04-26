#include<iostream> // use for input output cin/cout function
using namespace std; // to avoid writing std:: with each i/o function

int main(){ // automatic call in heap stack memory when the program run with return type int
    cout << "\"cout\" use for display the content";

    cout << endl; // use for go to next line but it uses the buffer befor print the data to store and then display so for large number of times exicution it takes long time so for that we can use the alternat method escape character "\n" is also use for change the line go in next line
    cout << "change the line using \"\\n\" \nnow we are in new line\n";

    // endl can write using \n in such a way -
    cout << "\"endl\" can write using \"\\n\" in such a way - \" \\n with cout.flush();\" \n";
    cout.flush();
    // above the both line present endl so endl use extra cout.flush() buffer take extra system call which was expensive

    cout << "conclusion is = \"endl\" forces a buffer flush so that \"endl\" slower than \"\\n\"";
}
