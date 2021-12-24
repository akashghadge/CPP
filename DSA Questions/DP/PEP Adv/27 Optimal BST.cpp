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
int optimal_bst(vi freq, int n)
{
    vii dp(n, vi(n));
    vi prefix_sum(n);
    for (int i = 0; i < n; i++)
    {
        prefix_sum[i] = freq[i] + (i == 0 ? 0 : prefix_sum[i - 1]);
    }

    for (int gap = 0; gap < n; gap++)
    {
        for (int j = gap, i = 0; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = freq[i];
            }
            else if (gap == 1)
            {
                int freq1 = freq[i];
                int freq2 = freq[j];
                dp[i][j] = min(freq1 + freq2 * 2, freq1 * 2 + freq2);
            }
            else
            {
                int min_value = INT_MAX;
                int curr_addition = prefix_sum[j] - ((i == 0) ? 0 : prefix_sum[i]);
                for (int k = i; k <= j; k++)
                {
                    cout << "Error " << gap << " "
                         << " " << i << " " << j << " " << k << en;
                    int left_part = (k == i) ? 0 : dp[i][k - 1];
                    int right_part = (k == j) ? 0 : dp[k - 1][j];
                    min_value = min(min_value, left_part + right_part + curr_addition);
                }
                dp[i][j] = min_value;
            }
        }
    }
    return dp[0][n - 1];
}
int pep(vi frequency, vi keys, int n)
{
    vi fsum(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            fsum[i] = frequency[i];
        }
        else
        {
            fsum[i] = frequency[i] + fsum[i - 1];
        }
    }

    vii cost(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        int si = 0;
        int ei = gap;
        while (ei < n)
        {
            if (gap == 0)
            {
                // diagonal
                cost[si][ei] = frequency[si];
            }
            else if (gap == 1)
            {
                int sum = fsum[ei];
                if (si - 1 >= 0)
                {
                    sum -= fsum[si - 1];
                }
                cost[si][ei] = min(cost[si][ei - 1], cost[si + 1][ei]) + sum;
            }
            else
            {
                cost[si][ei] = INT_MAX;
                int sum = fsum[ei];
                if (si - 1 >= 0)
                {
                    sum -= fsum[si - 1];
                }
                for (int i = si; i < ei - 1; i++)
                {
                    cost[si][ei] = min(cost[si][i] + cost[i + 2][ei] + sum, cost[si][ei]);
                }
                cost[si][ei] = min(min(cost[si][ei - 1], cost[si + 1][ei]) + sum, cost[si][ei]);
            }
            si++;
            ei++;
        }
    }
    return cost[0][n - 1];
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    // cout << optimal_bst(vec, N) << en;
    cout << pep(vec, vec, N);
    return 0;
}