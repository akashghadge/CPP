/*
1. Reverse Lp and Rn. We get [Lp] -> [Lp'] and [Rn] -> [Rn']
    [Ln Lp Rn Rp] -> [Ln Lp’ Rn’ Rp]

2. Reverse [Lp’ Rn’]. We get [Rn Lp].
    [Ln Lp’ Rn’ Rp] -> [Ln Rn Lp Rp]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(int arr[], int l, int mid, int r)
    {
        int i = l, j = mid + 1;
        while (i <= mid and arr[i] < 0)
            i++;
        while (j <= r and arr[j] < 0)
            j++;
        reverse(arr + i, arr + (mid + 1));
        reverse(arr + (mid + 1), arr + (j));
        reverse(arr + i, arr + (j));
    }
    void merge_sort(int arr[], int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int mid = (r + l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    void Rearrange(int arr[], int n)
    {
        merge_sort(arr, 0, n - 1);
    }
};
int main()
{
}