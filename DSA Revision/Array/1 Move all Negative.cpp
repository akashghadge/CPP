/*

*/
#include <bits/stdc++.h>
using namespace std;
void move_all_neg(vector<int> &arr, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] >= 0)
        {
            swap(arr[i], arr[j--]);
        }
        else
        {
            i++;
        }
    }
    for (auto val : arr)
        cout << val << " ";
    cout << endl;
}
int main()
{
    vector<int> arr = {2, 3, 4, -2, -3, -3, 3, -2, -2};
    move_all_neg(arr, arr.size());
}