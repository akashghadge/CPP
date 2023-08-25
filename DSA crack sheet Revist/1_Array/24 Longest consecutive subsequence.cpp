/*
We try to cut of the element which have higher element present so we have only ends of subsequences
*/
#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];

        mp[val] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (mp.find(val + 1) != mp.end())
        {
            mp[val + 1] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (mp[val] == 1)
        {
            int i = val;
            while (mp.find(i) != mp.end())
                i++;
            ans = max(ans, i - val);
        }
    }
    return ans;
}

int main()
{
}