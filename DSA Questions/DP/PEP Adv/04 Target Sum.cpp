/*
same as target sum subset but here we need to print the subsets as well
5
4
2
7
1
3
10
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
    int i;
    int j;
    string ans;
    Node(int i, int j, string ans)
    {
        this->i = i;
        this->j = j;
        this->ans = ans;
    }
};
void sol(vi &arr, int target)
{
    int n = arr.size();
    vii dp(n + 1, vi(target + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
            else
            {
                int val = arr[i - 1];
                dp[i][j] = dp[i - 1][j] || (j >= val && dp[i - 1][j - val] ? true : false);
            }
        }
    }
    queue<Node *> q;
    q.push(new Node(n, target, ""));
    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();
        int i = curr_node->i;
        int j = curr_node->j;
        string ans = curr_node->ans;
        if (i == 0 || j == 0)
        {
            cout << curr_node->ans << en;
            continue;
        }
        int curr_val = arr[i - 1];
        if (j >= curr_val && dp[i - 1][j - curr_val])
            q.push(new Node(i - 1, j - curr_val, to_string(i - 1) + " " + ans));
        if (dp[i - 1][j])
            q.push(new Node(i - 1, j, ans));
    }
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
    int target;
    cin >> target;
    sol(vec, target);
    return 0;
}