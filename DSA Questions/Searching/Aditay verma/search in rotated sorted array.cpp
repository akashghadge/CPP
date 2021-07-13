/*
so
4 5 6 1 2 3
search 5 
just return index 1
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int binarySearch(vi arr, int target, int low, int high)
{
    int mid;
    while (high >= low)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int util(vi arr)
{
    // basically we have some cases
    int low = 0;
    int high = arr.size();
    int start = 0;
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[start])
        {
            high = mid - 1;
        }
        else if (arr[mid] > arr[start])
        {
            low = mid + 1;
        }
    }
    return -1;
}
int sol(vi arr, int target)
{
    // basically we have some cases
    int part = util(arr);
    cout << "part :" << part << en;
    int r1 = binarySearch(arr, target, 0, part);
    int r2 = binarySearch(arr, target, part + 1, arr.size());
    if (r1 == -1 && r2 == -1)
    {
        return -1;
    }
    else if (r1 != -1)
    {
        return r1;
    }
    else
    {
        return r2;
    }
    return -1;
}
int main()
{
    FAST;
    int N, target;
    cin >> N;
    cin >> target;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << sol(arr, target) << en;
    return 0;
}