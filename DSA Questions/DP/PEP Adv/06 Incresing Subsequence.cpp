/*
we have array of number and we need to give max subsequence 
Constraints
0 <= n <= 20
0 <= n1, n2, .. <= 100
Sample Input
10
10
22
9
33
21
50
41
60
80
1
Sample Output
6
*/
/*
here we fill the dp with longest increasing subsequence (lis) which finshes on that element 
*/
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
int increasing_sub(vi arr, int n)
{
    vi dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int max_sub_till_now = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                max_sub_till_now = max(max_sub_till_now, dp[j]);
        }
        dp[i] = max_sub_till_now + 1;
    }
    return *max_element(dp.begin(), dp.end());
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
    cout << increasing_sub(arr, N) << en;
    return 0;
}