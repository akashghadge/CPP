/*
burst balloones 
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
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int burst(vi ball, int n)
{
    vii dp(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int j = gap, i = 0; j < n; j++, i++)
        {
            int max_value = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left_ans = k == i ? 0 : dp[i][k - 1];
                int right_ans = k == j ? 0 : dp[k + 1][j];
                int curr_ans = (i == 0 ? 1 : ball[i - 1]) * ball[k] * (j == n - 1 ? 1 : ball[j + 1]);
                max_value = max(max_value, left_ans + curr_ans + right_ans);
            }
            dp[i][j] = max_value;
        }
    }
    // printVector(dp);
    return dp[0][n - 1];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi ball(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ball[i];
    }
    cout << burst(ball, N) << en;
    return 0;
}