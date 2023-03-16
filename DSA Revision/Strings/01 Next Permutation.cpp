/*
1 2 3
->
2 1 or 3

1 3 2
2 1 3
*/

/*

*/
#include <bits/stdc++.h>
using namespace std;
void next_per(vector<int> &arr, int n)
{
    if (n == 1 or n == 0)
        return;
    int b = -1;
    // 3 2 1
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            b = i;
            break;
        }
    }
    if (b == -1)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        int nge = b;
        for (int i = b + 1; i < n; i++)
        {
            if (arr[i] > arr[b])
            {
                nge = i;
            }
        }
        swap(arr[nge], arr[b]);
        reverse(arr.begin() + b + 1, arr.end());
    }
}
int main()
{
    vector<int> a1 = {1, 2, 3, 4};
    vector<int> a2 = {1, 2, 3, 4};
    do
    {
        for (auto val : a1)
            cout << val << " ";
        cout << endl;
        for (auto val : a2)
            cout << val << " ";
        cout << endl;
        next_per(a2, a2.size());
    } while (next_permutation(a1.begin(), a1.end()));
}