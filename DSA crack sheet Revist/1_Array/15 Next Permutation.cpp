/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return;
        int i = n - 1;
        // find breakpoint
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                break;
            }
        }
        if (i == -1)
        {
            // no breakpoint
            reverse(arr.begin(), arr.end());
        }
        else
        {
            // get the smallest element than break point
            for (int j = n - 1; j >= i; j--)
            {
                if (arr[i] < arr[j])
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
            // make this permuation not just next but smallest next by getting all smaller element first
            reverse(arr.begin() + (i + 1), arr.end());
        }
    }
};
int main()
{
}