#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int kaden(vi arr, int n)
{
    int ans = 0;
    int curr_ans = 0;
    for (auto val : arr)
    {
        if (curr_ans <= 0)
        {
            curr_ans = 0;
        }
        curr_ans += val;
        ans = max(ans, curr_ans);
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
    cout << kaden(arr, N) << en;
    return 0;
}