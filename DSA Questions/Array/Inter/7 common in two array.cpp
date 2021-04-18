#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
vector<int> common(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.find(arr2[i]) != mp.end())
        {
            if (mp[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
    }
    return ans;
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    int arr1[] = {1, 1, 2, 3, 4};
    int arr2[] = {1, 2, 2, 2, 1};
    vector<int> ans = common(arr1, arr2, 5, 5);
    sort(ans.begin(), ans.end());
    printVector(ans);
}