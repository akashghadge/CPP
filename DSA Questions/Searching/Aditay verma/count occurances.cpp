/*
count occ  in sorted array
1 2 3 3 3 3 4 for 3
3 have 4 occ
*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vi sol(vi &, int);
int solOcc(vi &arr, int target)
{
    vi ans = sol(arr, target);
    return (ans[1] - ans[0]) + 1;
}
vi sol(vi &arr, int target)
{
    vi ans(2);
    int low = 0;
    int high = arr.size();
    int mid = 0;
    int lowerIndex = -1;
    while (high - low > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            lowerIndex = mid;
            high = mid - 1;
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
    // cout << lowerIndex << en;

    // for upper index
    low = 0;
    high = arr.size();
    int upperIndex = -1;
    while (high - low > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            upperIndex = mid;
            low = mid + 1;
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
    cout << lowerIndex << en;
    cout << upperIndex << en;
    ans[0] = lowerIndex;
    ans[1] = upperIndex;
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
    int target;
    cin >> target;
    vi ans = sol(arr, target);
    cout << "first occ : " << ans[0] << en;
    cout << "last occ : " << ans[1] << en;

    int occ = solOcc(arr, target);
    cout << occ << en;
    return 0;
}