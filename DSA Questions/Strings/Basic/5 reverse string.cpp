#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int n = str.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << str << en;
    reverse(str.begin(), str.end());
    cout << str;
}