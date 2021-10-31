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
void print(int arr[], int i, int n)
{
    if (i == n)
        return;
    int newI = i;
    print(arr, ++newI, n);
    cout << arr[i] << en;
}
int main()
{
    FAST;
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 0, n);
    return 0;
}