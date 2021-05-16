#include <bits/stdc++.h>
using namespace std;
int chocoDist(int *arr, int n, int M)
{
    sort(arr, arr + n);
    int minDiff = INT_MAX;
    for (int i = 0, j = M - 1; j < n; i++, j++)
    {
        minDiff = min(minDiff, arr[j] - arr[i]);
    }
    return minDiff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, M;
    cin >> M;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << chocoDist(arr, n, M) << "\n";
    return 0;
}