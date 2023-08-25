/*
There is Constant space approach by 0/1 sorting but it is hard to implement and research paper is 17 pages long
and o(N^0.05) approach on leetcode
https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/1723009/c-o-n-time-o-n-0-5-space-solution/
*/
#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n)
{
    // code here
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
        if (0 <= arr[i])
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    int i = 0, j = 0, k = 0, a = pos.size(), b = neg.size();
    while (i < a and j < b)
    {
        if (k & 1)
            arr[k++] = neg[j++];
        else
            arr[k++] = pos[i++];
    }
    while (i < a)
        arr[k++] = pos[i++];
    while (j < b)
        arr[k++] = neg[j++];
}

int main()
{
}