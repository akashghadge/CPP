#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
ll maxsum_subarray_k(vll arr, ll n, ll k)
{
    ll ans = INT_MIN;
    ll curr = 0;
    vi max_subarray(n, 0);
    max_subarray[0] = arr[0];
    curr = arr[0];
    for (ll i = 1; i < n; i++)
    {
        if (curr > 0)
        {
            curr += arr[i];
        }
        else
        {
            curr = arr[i];
        }
        max_subarray[i] = curr;
    }

    ll k_sum = 0;
    for (ll i = 0; i < k; i++)
    {
        k_sum += arr[i];
    }
    ans = max(ans, k_sum);
    for (ll i = k; i < n; i++)
    {
        k_sum = k_sum - arr[i - k] + arr[i];
        ans = max(ans, k_sum);
        ll window_and_left = max_subarray[i - k] + k_sum;
        ans = max(ans, window_and_left);
    }
    return ans;
}
ll main()
{
    FAST;
    ll N;
    cin >> N;
    vi arr(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    ll k;
    cin >> k;
    cout << maxsum_subarray_k(arr, N, k) << en;
    return 0;
}