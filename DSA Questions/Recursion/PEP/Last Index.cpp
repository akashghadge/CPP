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
    int res = print(arr, i + 1, n, target);
    if (res == -1)
    {
        if (arr[i] == target)
            return i;
        else
            return -1;
    }
    else
        return res;
}
int main()
{
    FAST;
    int n = 9;
    int arr[] = {10, 2, 4, 5, 333, 2, 3, 333, 44, 333};
    cout << print(arr, 0, 10, 333) << en;
    return 0;
}