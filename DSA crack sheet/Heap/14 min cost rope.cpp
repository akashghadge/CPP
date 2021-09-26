/*

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
//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<ll, vector<ll>, greater<ll>> ropes;
    for (ll i = 0; i < n; i++)
    {
        ropes.push(arr[i]);
    }
    ll costs = 0;
    while (ropes.size() != 1)
    {
        ll r1 = ropes.top();
        ropes.pop();
        ll r2 = ropes.top();
        ropes.pop();
        ll cost = r1 + r2;
        costs += cost;
        ropes.push(r1 + r2);
    }

    return costs;
}

int main()
{
    FAST;

    return 0;
}