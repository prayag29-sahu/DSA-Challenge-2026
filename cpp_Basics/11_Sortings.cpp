#include<iostream>
using namespace std;

class sorting{
    public: 
    void selection_sort(int num[],int n){
        for (int i = 0; i < n-1;++i){
            int min = i;
            for (int j = i+1; j < n;++j){
                if (num[j]<=num[min])
                    min = j;
            }
            int temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
};

int main(){
    sorting s;
    int arr[] = {5, 2, 4, 1, 7, 5};
    int n = 6;
    s.selection_sort(arr, n);
    for (int i = 0; i < n;++i){
        cout << arr[i]<< " ";
    }
}