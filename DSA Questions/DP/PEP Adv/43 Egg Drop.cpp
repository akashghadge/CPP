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
        cout << en;
    }
    cout << endl;
}
int egg_drop(int floor, int egg)
{
    vii dp(egg + 1, vi(floor + 1));
    for (int i = 1; i <= egg; i++)
    {
        for (int j = 1; j <= floor; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int worst_case = INT_MAX;
                for (int br = j - 1, sr = 0; br >= 0; br--, sr++)
                {
                    int survive = dp[i][br];
                    int breaks = dp[i - 1][sr];
                    int curr_ans = max(survive, breaks);
                    worst_case = min(curr_ans, worst_case);
                }
                dp[i][j] = worst_case + 1;
            }
        }
    }
    return dp[egg][floor];
}
int main()
{
    FAST;
    int egg, floor;
    cin >> egg >> floor;
    cout << egg_drop(floor, egg) << en;
    return 0;
}