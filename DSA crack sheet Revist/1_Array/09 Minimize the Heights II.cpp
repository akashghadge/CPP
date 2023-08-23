/*
https://medium.com/@kapoorprakhar99/minimize-the-maximum-difference-between-the-heights-851c6d8dd540
here main concept is we use two pointer approach where
we have base answer from diff between last - first
and we fix two points last and first and try to find new max and min by i and i+1 and update answer
*/
#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    // code here
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int mx, mn;
    for (int i = 1; i < n; i++)
    {
        mx = max(arr[n - 1] - k, arr[i - 1] + k);
        mn = min(arr[0] + k, arr[i] - k);
        if (mn < 0)
            continue;
        ans = min(ans, mx - mn);
    }
    return ans;
}
int main()
{
}