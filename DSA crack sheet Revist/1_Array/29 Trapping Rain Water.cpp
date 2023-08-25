/*

*/
#include <bits/stdc++.h>
using namespace std;
long long trappingWater(int arr[], int n)
{
    // code here
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(min(left[i], right[i]) - arr[i], 0);
    }
    return ans;
}
int main()
{
}