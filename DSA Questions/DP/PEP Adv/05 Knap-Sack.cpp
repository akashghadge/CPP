/*
print selection as well

5
15 14 10 45 30
2 5 1 3 4
7
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
class Node
{
public:
    int i, j;
    string ans;
    Node(int i, int j, string ans)
    {
        this->i = i;
        this->j = j;
        this->ans = ans;
    };
};

void sol(vi price, vi weight, int n, int capicity)
{
    vector<vi> dp(n + 1, vi(capicity + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capicity; j++)
        {
            if (j >= weight[i - 1])
            {
                int rem_weight = j - weight[i - 1];
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][rem_weight] + price[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][capicity] << en;
    queue<Node *> q;
    q.push(new Node(n, capicity, ""));
    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();
        int i = curr_node->i;
        int j = curr_node->j;
        string ans = curr_node->ans;
        if (i == 0 or j == 0)
        {
            cout << ans << en;
            continue;
        }
        // if ans is not found
        int curr_weight = weight[i - 1];
        int curr_price = price[i - 1];

        int excluded = dp[i - 1][j];
        if (dp[i][j] == excluded)
            q.push(new Node(i - 1, j, ans));

        if (j >= curr_weight)
        {
            int include = dp[i - 1][j - curr_weight] + curr_price;
            if (dp[i][j] == include)
                q.push(new Node(i - 1, j - curr_weight, to_string(i - 1) + " " + ans));
        }
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi price(N);
    vi weight(N);
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    int capicity;
    cin >> capicity;
    sol(price, weight, N, capicity);
}