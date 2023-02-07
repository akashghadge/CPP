/*

*/
#include <bits/stdc++.h>
using namespace std;
/*
void solve(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}

void solve(vector<int> &arr, int n)
{
    unordered_set<int> mp;
    for (auto val : arr)
        mp.insert(val);
    for (int i = 1; i <= n; i++)
        if (mp.find(i) == mp.end())
        {
            cout << i << endl;
            break;
        }
}
*/
void solve(vector<int> &arr, int n)
{
    int x = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        x ^= i;
    }
    for (int i = 0; i < n; i++)
    {
        x ^= arr[i];
    }
    int rsb = x & ~(-x);
    
    cout << x << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 7};
    solve(arr, arr.size());
}