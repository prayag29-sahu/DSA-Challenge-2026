#include<iostream>
using namespace std;

struct Linklist {
    int val;
    Linklist *next;
    Linklist (int x) : val(x), next(nullptr) {};
};

Linklist* Reverse_List(Linklist* head){
    if(!head || !head->next)
        return head;

    Linklist *prev = nullptr;
    Linklist *curr = head;

    while(curr){
        Linklist *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    Linklist* l1 = new Linklist(1);
    l1->next = new Linklist(2);
    l1->next->next = new Linklist(3);
    l1->next->next->next = new Linklist(4);

    Linklist *rev = Reverse_List(l1);
    while(rev){
        cout << rev->val << " -> ";
        rev = rev->next;
    }
    return 0;
}