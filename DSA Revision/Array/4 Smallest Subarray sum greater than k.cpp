#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> a, int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;
    while (i <= j and j < n)
    {
        sum += a[j];
        while (sum - a[i] >= k)
            sum -= a[i++];
        if (sum >= k)
            ans = min(ans, j - i + 1);
        j++;
    }
    cout << ans << endl;
}
int get()
{
    int k;
    cin >> k;
    return k;
}
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    solve(a, a.size(), get());
}