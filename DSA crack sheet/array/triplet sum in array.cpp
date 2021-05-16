#include <bits/stdc++.h>
using namespace std;
int triplets(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int tripletsOptimise(int *arr, int n, int target)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k && j < n && k < n)
        {
            int val = arr[i] + arr[j] + arr[k];
            if (val == target)
            {
                return 1;
            }
            else if (val < target)
            {
                j++;
            }
            else if (val > target)
            {
                k--;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << triplets(arr, n, target) << "\n";
    cout << tripletsOptimise(arr, n, target) << "\n";
    return 0;
}