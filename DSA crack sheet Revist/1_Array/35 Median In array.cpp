/*

*/
#include <bits/stdc++.h>
using namespace std;
int find_median(vector<int> a)
{
    // Code here.
    sort(a.begin(), a.end());
    int n = a.size();
    if (n & 1)
    {
        return a[n / 2];
    }
    else
    {
        return (a[(n / 2)] + a[(n / 2) - 1]) / 2;
    }
}
int main()
{
}