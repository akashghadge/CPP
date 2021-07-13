#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(vi &arr, int target)
{
    ll interval = 1;
    while (arr[interval] <= target)
    {
        interval <<= 1;
    }
    int low = interval >> 1;
    int high = interval;
    int mid;
    while (low <= high)
    {
        mid = (high - low) / 2 + low;
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
int main()
{
    FAST;
    int N, target;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> target;
        cout << sol(arr, target) << en;
    }

    return 0;
}