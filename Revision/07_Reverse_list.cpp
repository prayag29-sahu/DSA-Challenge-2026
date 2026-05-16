#include <iostream>
using namespace std;

struct list
{
    int val;
    list *next;
    list(int x)
    {
        val = x;
        next = nullptr;
    }
};

list* Reverse(list *l1)
{
    if(!l1 || !l1->next){
        return l1;
    }
    list *prev = nullptr;
    list *curr = l1;
    while(curr){
        list *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    list *l1 = new list(1);
    l1->next = new list(2);
    l1->next->next = new list(3);
    l1->next->next->next = new list(4);
    l1->next->next->next->next = new list(5);
    list *temp = Reverse(l1);
    while(temp){
        cout << temp->val;
        if(temp->next)
            cout << "->";
        temp=temp->next;
    }
    cout << "->nullptr";
}