/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int sum = INT_MIN;
        int curr = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            curr += arr[i];
            sum = max(sum, curr);
            if (curr < 0)
            {
                curr = 0;
            }
        }
        return sum;
    }
};
int main()
{
}