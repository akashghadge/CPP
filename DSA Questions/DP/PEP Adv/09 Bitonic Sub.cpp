/*
find longest bitonic subsequence 
sequence will initially grow then fall

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
3


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
int bitonic_sub(vi arr, int n)
{
    vi increase(n);
    vi decrease(n);

    for (int i = 0; i < n; i++)
    {
        int max_sub = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j] && max_sub < increase[j])
            {
                max_sub = increase[j];
            }
        }
        increase[i] = max_sub + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int max_sub = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] >= arr[j] && max_sub < decrease[j])
            {
                max_sub = decrease[j];
            }
        }
        decrease[i] = max_sub + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cout << increase[i] << " " << decrease[i] << en;
        ans = max(ans, increase[i] + decrease[i] - 1);
    }
    return ans;
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
    cout << bitonic_sub(arr, N) << en;
    return 0;
}