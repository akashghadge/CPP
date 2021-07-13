/*
1 2 3 4 5 6
rotate at 3
5 6 7 8 9 10 1 2 3 4
so pivot point is 6
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int sol(vi nums)
{
    // basically we have some cases
    int N = nums.size();
    int l = 0;
    int h = N - 1;
    int m = 0;
    int ANS = 0;
    if (nums[l] < nums[h])
    {
        return nums[0];
    }
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (m > 0 && nums[m] < nums[m - 1])
        {
            return nums[m];
        }
        if (m < N - 1 && nums[m] > nums[m + 1])
        {
            return nums[m + 1];
        }
        else if (nums[m] > nums[h])
        {
            l = m + 1;
        }
        else
        {
            ANS = m;
            h = m - 1;
        }
    }
    return nums[ANS];
}
int main()
{
    // FAST;
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