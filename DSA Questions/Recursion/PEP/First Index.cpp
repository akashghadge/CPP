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
int print(int arr[], int i, int n, int target)
{
    if (i == n)
        return -1;
    else if (target == arr[i])
        return i;
    else
        return print(arr, i + 1, n, target);
}
int main()
{
    FAST;
    int n = 9;
    int arr[] = {10, 2, 4, 5, 333, 2, 3, 333, 44};
    cout << print(arr, 0, n, 0);
    return 0;
}