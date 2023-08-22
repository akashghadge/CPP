/*

*/
#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    // Your code here
    int ans = 0;
    int max_ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (ans < 0)
        {
            ans = arr[i];
        }
        else
        {
            ans += arr[i];
        }
        max_ans = max(max_ans, ans);
    }
    return max_ans;
}

int main()
{
}