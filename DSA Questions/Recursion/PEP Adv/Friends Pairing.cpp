/*
n is given
e.g n=3
1 (1)(2)(3)
2 (1,2)(3)
3 (1)(2,3)
4 (1,3)(2)
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void helper(int curr, int total, vector<bool> used, string ans)
{
    if (curr > total)
    {
        cout << ans << en;
        return;
    }
    if (used[curr] == true)
        helper(curr + 1, total, used, ans);
    else
    {
        used[curr] = true;
        helper(curr + 1, total, used, ans + "(" + to_string(curr) + ")");
        for (int i = curr + 1; i <= total; i++)
        {
            if (used[i] == false)
            {
                used[i] = true;
                helper(curr + 1, total, used, ans + "(" + to_string(curr) + "," + to_string(i) + ")");
                used[i] = false;
            }
        }

        used[curr] = false;
    }
}
void sol(int n)
{
    vector<bool> used(n + 1, false);
    helper(1, n, used, "");
}
int main()
{
    FAST;
    int n;
    cin >> n;
    sol(n);
    return 0;
}