/*
here we have array
print the sum of subset of array which have
no adjansant elements
have max sum
*/
/*
for this question as well we follow exlude include approch
i.e.
here we make two variables
inc = arr[0]
exc = 0 
and after that for each iteration we will 
use this algo
get next include by exc + arr[i]
get next exlude by max of inc exc
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
int sol(vi arr)
{
    if (arr.size() == 0)
        return 0;
    int exc = 0;
    int inc = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int ne = max(inc, exc);
        int ni = exc + arr[i];
        inc = ni;
        exc = ne;
    }
    return max(inc, exc);
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << sol(arr) << en;
    return 0;
}