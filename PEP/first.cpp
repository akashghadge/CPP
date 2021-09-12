#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(int currH, int currM, int reqH, int reqM)
{
    int solH = min(abs(reqH - currH), abs(24 - reqH) + currH);
    int solM = min(abs(reqM - currM), abs(60 - reqM) + currM);
    return solH + solM;
}
int main()
{
    FAST;
    int currH, currM;
    int reqH, reqM;
    cin >> currH >> currM;
    cin >> reqH >> reqM;
    cout << sol(currH, currM, reqH, reqM) << en;
    return 0;
}