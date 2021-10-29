#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// 5 -4 1 -3 1
int sol(int shops[], int N)
{
    vector<pair<int, int>> buyers;
    vector<pair<int, int>> sellers;
    for (int i = 0; i < N; i++)
    {
        if (shops[i] < 0)
        {
            sellers.push_back({shops[i], i});
        }
        else
        {
            buyers.push_back({shops[i], i});
        }
    }
    int i = 0, j = 0;
    int ans = 0;
    while (i < buyers.size() && j < sellers.size())
    {
        int maxAmountOfTrade = min(buyers[i].first, -sellers[j].first);
        buyers[i].first -= maxAmountOfTrade;
        sellers[j].first += maxAmountOfTrade;
        int positionDiff = abs(buyers[i].second - sellers[j].second);
        ans += (maxAmountOfTrade * positionDiff);
        if (buyers[i].first == 0)
            i++;
        if (sellers[j].first == 0)
            j++;
    }
    return ans;
}
int main()
{
    FAST;
    while (1)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;
        int shops[N];
        for (int i = 0; i < N; i++)
        {
            cin >> shops[i];
        }
        cout << sol(shops, N) << en;
    }
    return 0;
}