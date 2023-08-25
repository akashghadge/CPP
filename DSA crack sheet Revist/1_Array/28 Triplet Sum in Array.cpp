/*

*/
#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int a[], int n, int x)
{
    // Your Code Here
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int val = a[i] + a[j] + a[k];
            if (val == x)
                return true;
            else if (val > x)
                k--;
            else
                j++;
        }
    }
    return false;
}
int main()
{
}