/*

*/
#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    long long mn = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i <= n - m; i++)
    {
        // cout<<a[i+m-1]-a[i]<<endl;
        mn = min(a[i + m - 1] - a[i], mn);
    }
    return mn;
}
int main()
{
}