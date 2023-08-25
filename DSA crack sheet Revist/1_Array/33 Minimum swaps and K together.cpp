/*
Efficient Approach:  We can use the two-pointer technique and a sliding window.

1) Find the count of all elements which are less than or equal to ‘k’. Let’s say the count is ‘cnt’
2) Using the two-pointer technique for a window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
3) Repeat step 2, for every window of length ‘cnt’ and take a minimum of count ‘bad’ among them. This will be the final answer.

*/
#include <bits/stdc++.h>
using namespace std;
int minSwap(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;

    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {
        if (arr[i] > k) 
            --bad;
        if (arr[j] > k)
            ++bad;
        ans = min(ans, bad);
    }
    return ans;
}

int main()
{
}