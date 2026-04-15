#include<iostream>
using namespace std;

struct LinkList {
    int val;
    LinkList *next;
    LinkList (int x) : val(x), next(nullptr)  {};
};

LinkList* mergeTwoSortedList(LinkList* l1, LinkList* l2){
    LinkList dummy(0);
    LinkList *temp = &dummy;

    while(l1 && l2){
        if(l1->val <= l2->val){
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    temp->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(LinkList* temp){

    while(temp){
        cout << temp->val;
        if (temp->next) cout<< " -> ";
        temp = temp->next;
    }
    cout << " -> NullPtr";
}

int main()
{
    LinkList *l1 = new LinkList(1); // l1  : 1,2,4
    l1->next = new LinkList(2);
    l1->next->next = new LinkList(4);
    LinkList *l2 = new LinkList(1); // l2 : 1,1,5
    l2->next = new LinkList(1);
    l2->next->next = new LinkList(5);
    printList(mergeTwoSortedList(l1, l2));
    return 0;
}