/*
1 2 3 4 5 6
rotate at 3
5 6 7 8 9 10 1 2 3 4
so pivot point is 6
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(vi arr)
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
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << sol(arr) << en;
    return 0;
}