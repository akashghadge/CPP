/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size(), mx = arr[n - 1], ans = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            ans = max(ans, mx - arr[i]);
            mx = max(mx, arr[i]);
        }
        return ans;
    }
};
int main()
{
}