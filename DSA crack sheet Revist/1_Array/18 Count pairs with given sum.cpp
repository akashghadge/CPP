/*

*/
#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    // code here
    int cn = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        mp[curr]--;
        if (mp.find(k - curr) != mp.end())
        {
            cn += mp[k - curr];
        }
        mp[curr]++;
    }
    return cn / 2;
}
int main()
{
}