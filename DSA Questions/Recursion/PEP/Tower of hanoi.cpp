/*
get towers name and number of discs as  input and print instructions to move discs
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
int counter = 0;
void sol(int n, char a, char b, char c)
{
    counter++;
    if (n == 0)
        return;
    // move n-1 discs from a to c using the bth disc
    sol(n - 1, a, c, b);
    cout << "Move " << n << " from " << a << " to " << b << en;
    sol(n - 1, c, a, b);
}
int main()
{
    FAST;
    int n;
    char a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    // number of discs,source ,destination , use this tower
    sol(n, a, b, c);
    cout << counter << en;
    return 0;
}