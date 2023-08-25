/*

*/
#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &a, vector<int> &b)
{
    // Your code goes here
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    int k = 0;
    int sum = 0;
    int total = n + m;
    int f = total & 1;
    int mid = total / 2;
    while (i < n and j < m)
    {
        if (a[i] <= b[j])
        {
            if (!f and k == (mid - 1))
            {
                sum += a[i];
            }
            if (k == mid)
            {
                sum += a[i];
            }
            i++;
        }
        else
        {
            if (!f and k == (mid - 1))
            {
                sum += b[j];
            }
            if (k == mid)
            {
                sum += b[j];
            }
            j++;
        }
        k++;
    }

    while (i < n)
    {
        if (!f and k == (mid - 1))
        {
            sum += a[i];
        }
        if (k == mid)
        {
            sum += a[i];
        }
        i++;
        k++;
    }
    while (j < m)
    {
        if (!f and k == (mid - 1))
        {
            sum += b[j];
        }
        if (k == mid)
        {
            sum += b[j];
        }
        j++;
        k++;
    }
    // cout<<sum<<endl;
    return f ? sum : (double)sum / 2;
}

int main()
{
}