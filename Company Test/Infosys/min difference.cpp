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
void sol(vi arr)
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    for (int val : arr)
    {
        if (left.size() - 1 > right.size())
        {
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        else
        {
            left.push(val);
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    while (!left.empty())
    {
        sum1 += left.top();
        left.pop();
    }
    while (!right.empty())
    {
        sum2 += right.top();
        right.pop();
    }
    cout << sum1 << sum2 << en;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sol(arr);
    return 0;
}