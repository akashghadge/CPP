/*
so
4 5 6 1 2 3
search 5 
just return index 1
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(vi arr, int target)
{
    // basically we have some cases
    int low = 0;
    int high = arr.size();
    int size = arr.size();
    int start = 0;
    int mid;
    int ans = -1;
    while ((high - low) > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
        }
        else
        {
            
        }
    }
}
int main()
{
    FAST;
    int N, target;
    cin >> N;
    cin >> target;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << sol(arr, target) << en;
    return 0;
}