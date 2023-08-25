/*

*/
#include <bits/stdc++.h>
using namespace std;
long long maxProduct(vector<int> arr, int n)
{
    long long minVal = arr[0], maxVal = arr[0], maxProduct = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxVal, minVal);
        maxVal = max(1LL * arr[i], 1LL * maxVal * arr[i]);
        minVal = min(1LL * arr[i], 1LL * minVal * arr[i]);
        maxProduct = max(maxProduct, maxVal);
    }
    return maxProduct;
}
int main()
{
}