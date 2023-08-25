/*

*/
#include <bits/stdc++.h>
using namespace std;
int PalinArray(int a[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        string str = to_string(a[i]);
        int k = 0, j = str.size() - 1;
        while (k < j)
        {
            if (str[k++] != str[j--])
                return 0;
        }
    }
    return 1;
}
int main()
{
}