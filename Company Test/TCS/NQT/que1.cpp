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
int main()
{
    FAST;
    int A, B;
    int n = 100;
    cin >> A >> B;
    vi arr(n + 1, 0);
    for (int i = A; i <= n; i = i + A)
    {
        arr[i] = 1;
    }
    for (int i = B; i <= n; i = i + B)
    {
        arr[i] = 1;
    }
    int ptr = -1;
    for (int i = n; i >= 0; i--)
    {
        if (arr[i] == 0)
            break;
        ptr = i;
    }
    cout << ptr << en;

    return 0;
}