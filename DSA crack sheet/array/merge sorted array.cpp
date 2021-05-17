#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// complexity is O(nlogn)  and space is O(n+m);
void merge(int arr1[], int arr2[], int n, int m)
{
    int arr3[n + m];
    for (int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr3[n + i] = arr2[i];
    }
    sort(arr3, arr3 + n + m);
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr3[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = arr3[n + i];
    }
}

// complexity is O(n+m)  and space is O(n+m);
void mergeOp(int arr1[], int arr2[], int n, int m)
{
    int res[n + m];
    int i = 0, j = 0;
    int pt = 0;
    while (i != n && j != m)
    {
        if (arr1[i] < arr2[j])
        {
            res[pt] = arr1[i];
            i++;
        }
        else
        {
            res[pt] = arr2[j];
            j++;
        }
        pt++;
    }
    if (i != n)
    {
        while (i != n)
        {
            res[pt] = arr1[i];
            i++;
            pt++;
        }
    }
    if (j != m)
    {
        while (j != m)
        {
            res[pt] = arr2[j];
            j++;
            pt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr1[i] = res[i];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = res[n + i];
    }
}
void mergeOptimise(long long arr1[], long long arr2[], int n, int m)
{
    //Function to merge the arrays.
    // code here
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k
    // or j is less tha m
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    print(arr1, n);
    print(arr2, m);
    // merge(arr1, arr2, n, m);
    mergeOp(arr1, arr2, n, m);
    print(arr1, n);
    print(arr2, m);

    return 0;
}