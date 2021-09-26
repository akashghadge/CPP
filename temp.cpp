#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
bool isCube(int N)
{
    int start = 1, end = N;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * mid * mid == N)
        {
            return true;
        }
        if (mid * mid * mid < N)
        {
            start = mid + 1;
        }

        else
            end = mid - 1;
    }

    return false;
}
int numOfCube(vector<int> arr)
{
    int c = 0;
    for (auto val : arr)
    {
        if (isCube(val))
        {
            c++;
        }
    }
    return c;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << numOfCube(arr) << en;

    return 0;
}