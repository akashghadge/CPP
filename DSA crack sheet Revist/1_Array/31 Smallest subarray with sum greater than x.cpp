/*

*/
#include <bits/stdc++.h>
using namespace std;
int smallestSubWithSum(int arr[], int n, int x)
{
    // Your code goes here
    int start = 0;
    int curr = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr > x)
        {
            ans = min(ans, i - start + 1);
            while (curr - arr[start] > x)
            {
                curr -= arr[start++];
            }
            ans = min(ans, i - start + 1);
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main()
{
}