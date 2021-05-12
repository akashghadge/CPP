#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) 
    {
        long long m, n;
        long long ct = 0;
        cin >> n >> m;
        vector<long long> mp(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            mp[i] = 1;
        }
        for (long long a = 2; a <= n; a++)
        {
            long long x = m % a;
            ct += mp[x];
            for (long long b = x; b <= n; b += a)
            {
                mp[b]++;
            }
        }
        cout << ct << endl;
    }
    return 0;
}