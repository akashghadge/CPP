#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(int N, int K)
{
    if (N == 1)
    {
        return 0;
    }
    int res = sol(N - 1, K);
    return ((res + K) % N);
}
int main()
{
    FAST;
    int N, K;
    cin >> N >> K;
    cout << sol(N, K);
    return 0;
}