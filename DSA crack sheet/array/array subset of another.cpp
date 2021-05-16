#include <bits/stdc++.h>
using namespace std;
bool subset(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.find(arr2[i]) == mp.end())
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr2[m], arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << subset(arr1, arr2, n, m) << endl;

    return 0;
}