/*
123456
k =1
623451
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
int max_ans = INT_MIN;
int parseINT(string num)
{
    int mult = 1;
    int ans = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        ans += (mult * (num[i] - '0'));
        mult *= 10;
    }
    return ans;
}
void sol(string num, int k)
{
    int curr_ans = parseINT(num);
    max_ans = max(curr_ans, max_ans);
    if (k == 0)
    {
        return;
    }
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            string temp = num;
            if (temp[i] - '0' < temp[j] - '0')
            {
                swap(temp[i], temp[j]);
                sol(temp, k - 1);
            }
        }
    }
}
int main()
{
    FAST;
    string num;
    int k;
    cin >> num >> k;
    sol(num, k);
    cout << max_ans << en;
    return 0;
}