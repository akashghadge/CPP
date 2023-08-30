/*

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(int n, vector<int> arr)
{
    // code here
    int i = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }
    if (i == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    int mx = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        if (arr[j] > arr[i])
        {
            swap(arr[j], arr[i]);
            break;
        }
    }
    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}
int main()
{
}