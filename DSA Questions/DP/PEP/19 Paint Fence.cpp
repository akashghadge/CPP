/*
here we have n fence and k colors 
we need to paint fence such way that no more 2 adjusant have same color
i.e for rgb and n=6
rgggbb is wrong due to ggg 
rggbbr is write 
return count of ways that can possible
*/
// | | | | | |
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

int sol(int n, int k)
{
    int same = k;
    int diff = k * (k - 1);
    int total = same + diff;
    for (int i = 3; i <= n; i++)
    {
        same = diff;
        diff = total * (k - 1);
        total = same + diff;
    }
    return total;
}
int main()
{
    FAST;
    int n, k;
    cin >> n >> k;
    cout << sol(n, k) << en;
    return 0;
}
