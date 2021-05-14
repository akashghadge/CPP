#include <bits/stdc++.h>
using namespace std;
// editorial solution :)
class Solution
{
public:
    long long maxProduct(int *arr, int n)
    {
        // Variables to store maximum and minimum
        // product till ith index.
        long long minVal = arr[0];
        long long maxVal = arr[0];

        long long maxProduct = arr[0];

        for (int i = 1; i < n; i++)
        {

            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (arr[i] < 0)
                swap(maxVal, minVal);

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxVal = max(1LL * arr[i], 1LL * maxVal * arr[i]);
            minVal = min(1LL * arr[i], 1LL * minVal * arr[i]);

            // Max Product of array.
            maxProduct = max(maxProduct, maxVal);
        }

        // Return maximum product found in array.
        return maxProduct;
    }
};
int maxProduct(int *arr, int size)
{
    int m = 1;
    int curr = 1;
    int neg = 1;
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            curr = 1;
            neg = 1;
            flag = 1;
        }
        else if (arr[i] > 0)
        {
            curr *= arr[i];
            neg *= arr[i];
        }
        else if (arr[i] < 0)
        {
            if (flag)
            {
                flag = false;
                neg *= arr[i];
                curr = 1;
            }
            else
            {
                curr = neg * arr[i];
                neg = curr;
                flag = true;
            }
        }
        // cout << curr << " " << neg << endl;
        m = max(m, curr);
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n) << "\n";
    return 0;
}