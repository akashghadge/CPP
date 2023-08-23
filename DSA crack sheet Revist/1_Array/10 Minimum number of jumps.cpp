/*
mine intuition is like consider from first place we start with gas arr[0]
and for each index we take the max possible between previous backup jump and current jump length
when we found we ran out of gas we refill with back up and increment answer
cause back up will be max possible length
*/
#include <bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
{
    // Your code here
    if (!arr[0])
        return -1;
    int curr = arr[0] - 1, back = 0, ans = 1;
    for (int i = 1; i < n; i++)
    {
        back = max(back, arr[i]);
        if (i != n - 1 and curr == 0 and back <= 0)
        {
            return -1;
        }
        if (i != n - 1 and curr == 0)
        {
            ans++;
            curr = back;
        }
        back--;
        curr--;
    }
    return ans;
}
int main()
{
}