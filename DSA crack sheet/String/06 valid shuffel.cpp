/*
str1 -> xy
str2 -> 12
res -> x1y2
*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
bool sol(string str1, string str2, string res)
{
    int n, m, t;
    n = str1.size();
    m = str2.size();
    t = res.size();
    int i = 0, j = 0, k = 0;
    if (n + m != t)
        return false;
    while (k < t)
    {
        if (i < n && str1[i] == res[k])
            i++;
        else if (j < m && str2[j] == res[k])
            j++;
        else
            return false;
        k++;
    }
    if (i < n || j < m)
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2, res;
    cin >> str1 >> str2 >> res;
    cout << sol(str1, str2, res) << endl;
    return 0;
}