/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool predicate(vi &stalls, int Cow, int dist)
{
    int last_pos = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        if ((stalls[i] - last_pos) >= dist || last_pos == -1)
        {
            Cow--;
            last_pos = stalls[i];
        }
        if (Cow == 0)
            break;
    }
    return (Cow == 0);
}
int sol(vi &stalls, int Cow)
{
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = 1e9;
    int mid = 0;
    while ((high - low) > 1)
    {
        mid = (high + low) / 2;
        if (predicate(stalls, Cow, mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (high >= low && predicate(stalls, Cow, high))
    {
        return high;
    }
    return low;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int N, Cow;
        cin >> N >> Cow;
        vi stalls(N);
        for (int i = 0; i < N; i++)
        {
            cin >> stalls[i];
        }
        cout << sol(stalls, Cow) << en;
    }

    return 0;
}