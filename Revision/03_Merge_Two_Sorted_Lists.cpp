#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_2list(vector<int> &list1, vector<int> &list2)
{
    int list1_size = list1.size();
    int list2_size = list2.size();
    vector<int> list3;
    int l1 = 0;
    int l2 = 0;
    while (l1<list1_size && l2<list2_size)
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

int main()
{
    vector<int> list1 = {1, 3, 5, 7, 9};
    vector<int> list2 = {0, 2, 4, 6, 8};
    vector<int> results = merge_2list(list1, list2);
    for(int num : results){
        cout << num << " ";
    }
    return 0;
}