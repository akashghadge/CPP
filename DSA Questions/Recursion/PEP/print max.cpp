/*
function only have index and array
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
int print(int arr[], int i, int n)
{
    if (i == n - 1)
        return arr[i];
    int res = print(arr, i + 1, n);
    return max(res, arr[i]);
}
int main()
{
    FAST;
    int n = 5;
    int arr[] = {10, 2, 333, 4, 5};
    cout << print(arr, 0, n);
    return 0;
}