#include <bits/stdc++.h>
using namespace std;
void sort_two(vector<int> a, int n, vector<int> b, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k and j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            swap(a[k--], b[j++]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    for (auto val : b)
        cout << val << " ";
    cout << endl;
}
int main()
{
    vector<int> a = {4, 5, 6};
    vector<int> b = {1, 2, 3};
    sort_two(a, a.size(), b, b.size());
}