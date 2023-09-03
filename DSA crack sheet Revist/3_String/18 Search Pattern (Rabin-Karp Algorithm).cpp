/*
Please read this article don't skip just take glance this is most optimal implementation but we did'nt handle the collisions cause it is most unlikely to happen :)
https://cp-algorithms.com/string/string-hashing.html
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> search(string pat, string str)
{
    // code here.
    int p = pat.size(), s = str.size();
    int n = 1e5 + 10;
    int mod = 1e9 + 7;
    vector<int> ans;

    // precomputation
    vector<long long> power(n, 0);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * 31) % mod;

    // doing for current string
    vector<long long> hash(s + 1, 0);
    for (int i = 0; i < s; i++)
    {
        hash[i + 1] = (hash[i] + (((str[i] - 'a') + 1) * power[i]) % mod) % mod;
    }

    // for pattern
    long long curr = 0;
    for (int i = 0; i < p; i++)
    {
        curr = (curr + ((pat[i] - 'a') + 1) * power[i]) % mod;
    }

    for (int i = 0; i + p - 1 < s; i++)
    {
        int string_hash = (hash[i + p] - hash[i] + mod) % mod;
        if (string_hash == ((curr * power[i]) % mod))
        {
            ans.push_back(i + 1);
        }
    }
    if (!ans.size())
        ans.push_back(-1);
    return ans;
}
int main()
{
}