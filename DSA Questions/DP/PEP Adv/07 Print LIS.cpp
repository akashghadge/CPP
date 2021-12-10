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


test case 2
13
52
9
11
56
23
59
18
91
28
41
1
30
14
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
class Node
{
public:
    int i;
    string ans;
    Node(int i, string ans)
    {
        this->i = i;
        this->ans = ans;
    }
};
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

    int max_ans = *max_element(dp.begin(), dp.end());
    cout << max_ans << en;
    queue<Node *> q;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == max_ans)
            q.push(new Node(i, to_string(arr[i])));
    }

    while (!q.empty())
    {
        Node *curr_node = q.front();
        q.pop();
        int i = curr_node->i;
        string ans = curr_node->ans;
        if (dp[i] == 1)
        {
            cout << ans << en;
            continue;
        }

        int prev_subsequence = dp[i] - 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (prev_subsequence == dp[j] && arr[j] < arr[i])
            {
                q.push(new Node(j, to_string(arr[j]) + " -> " + ans));
            }
        }
    }
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
    increasing_sub(arr, N);
    return 0;
}