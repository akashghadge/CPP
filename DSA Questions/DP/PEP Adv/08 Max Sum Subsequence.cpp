
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
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] &&
                dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];
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