#include <bits/stdc++.h>
using namespace std;
int trappingRainwater(int *arr, int n)
{
    return 0;
}
int trappingRainwaterOpt(int *arr, int n)
{
    int l[n];
    int r[n];
    int rm = arr[n - 1];
    int lm = arr[0];
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        rm = max(arr[j], rm);
        lm = max(arr[i], lm);
        l[i] = lm;
        r[j] = rm;
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        int minVal = min(l[i], r[i]);
        if (minVal - arr[i] > 0)
        {
            water += minVal - arr[i];
        }
    }
    return water;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << trappingRainwater(arr, n) << "\n";
    cout << trappingRainwaterOpt(arr, n) << "\n";
    return 0;
}