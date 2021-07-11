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
int sol(vi arr, int target)
{
    // basically we have some cases
    int low = 0;
    int high = arr.size();
    int size = arr.size();
    int start = 0;
    int mid;
    int ans = -1;
    while ((high - low) > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            ans = mid;
            high = mid - 1;
            // break;
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
    return ans;
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