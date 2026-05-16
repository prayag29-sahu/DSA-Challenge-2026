#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// all posible 2 sum indexes
vector<int> Two_Sum_Indexes(vector<int> &nums, int target)
{
    unordered_map<int, int> val;
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (val.find(complement) != val.end())
        {
            result.push_back(val[complement]);
            result.push_back(i);
        }
        val[nums[i]] = i;
    }
    return result;
}

// all posible 2 sum values
vector<int> Two_Sum_Values(vector<int> &nums, int target)
{
    unordered_map<int, int> val;
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (val.find(complement) != val.end())
        {
            result.push_back(nums[val[complement]]);
            result.push_back(nums[i]);
        }
        val[nums[i]] = i;
    }
    return result;
}

// senerio : - user visit in shopsy website to buy cloths there have a filter user want to by 2 t-shirt but he have only 550/- now apply the filter in such a way that user can see the list of all combo t-shirt to buy it upto 550 range

vector<pair<string, string>>
Cloths_Filter(unordered_map<float, string> &cloths, float target)
{
    unordered_map<float, string> val;

    vector<pair<string, string>> result;

    for (auto &at : cloths)
    {
        float complement = target - at.first;
        if (val.find(complement) != val.end())
        {
            result.push_back({val[complement], at.second});
        }

        val[at.first] = at.second;
    }

    return result;
}

int main()
{
    // vector<int> nums = {2, 9, 6, 7, 11, 4, 5, 3};
    // int target = 9;
    // vector<int> results_Indexes = Two_Sum_Indexes(nums, target);
    // vector<int> results_values = Two_Sum_Values(nums, target);
    // int n = results_Indexes.size();
    // for (int i = 0; i < n; i = i + 2)
    // {
    //     cout << "Indexes : (" << results_Indexes[i] << ", " << results_Indexes[i + 1] << ") And Values : (" << results_values[i] << ", " << results_values[i + 1] << ")" << endl;
    // }

    unordered_map<float, string> cloths = {
        {200.00, "shirt1"},
        {150.00, "shirt2"},
        {300.00, "shirt3"},
        {290.00, "shirt5"},
        {250.00, "shirt6"},
        {260.00, "shirt7"},
        {220.00, "shirt8"},
        {350.00, "shirt9"},
    };

    float target = 550.00;

    vector<pair<string, string>> filter =
        Cloths_Filter(cloths, target);

    int i = 1;

    for (auto &at : filter)
    {
        cout << "Combo " << i << ": [ " << at.first << ", " << at.second << " ]\n";

        ++i;
    }

    return 0;
}