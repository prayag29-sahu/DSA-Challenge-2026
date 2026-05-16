#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// using vector
vector<int> merge_2list(vector<int> &list1, vector<int> &list2)
{
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int list1_size = list1.size();
    int list2_size = list2.size();
    vector<int> list3;
    int l1 = 0;
    int l2 = 0;
    while (l1 < list1_size && l2 < list2_size)
    {
        if (list1[l1] < list2[l2])
        {
            list3.push_back(list1[l1]);
            ++l1;
        }
        else
        {
            list3.push_back(list2[l2]);
            ++l2;
        }
    }
    while (l1 < list1_size)
    {
        list3.push_back(list1[l1]);
        ++l1;
    }
    while (l2 < list2_size)
    {
        list3.push_back(list2[l2]);
        ++l2;
    }
    return list3;
}

// using linked list
struct Linklist
{
    int val;
    Linklist *next;
    Linklist(int x)
    {
        val = x;
        next = nullptr;
    }
};

Linklist* merge_2linkedlist(Linklist *l1, Linklist *l2)
{
    Linklist l3(0); // direct creation
    Linklist *temp = &l3;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    temp->next = l1 ? l1 : l2;
    return l3.next;
}

void printList(Linklist* temp){
    while(temp){
        cout << temp->val;
        if(temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << " -> NullPtr";
}

int main()
{
    vector<int> list1 = {1, 0, 3, 5, 9, 2, 56, 23, 7, 9};
    vector<int> list2 = {0, 34, 2, 4, 22, 6, 8};
    vector<int> results = merge_2list(list1, list2);
    cout << "Merge 2 list using vector array : ";
    for (int num : results)
    {
        cout << num << " ";
    }

    Linklist *l1 = new Linklist(0); // dynamic creation 
    l1->next = new Linklist(1);
    l1->next->next = new Linklist(3);
    l1->next->next->next = new Linklist(5);
    l1->next->next->next->next = new Linklist(9);
    Linklist *l2 = new Linklist(0);
    l2->next = new Linklist(3);
    l2->next->next = new Linklist(12);
    l2->next->next->next = new Linklist(22);
    l2->next->next->next->next = new Linklist(41);
    cout << "\nMerge 2 list using Linked list : ";
    printList(merge_2linkedlist(l1, l2));

    return 0;
}