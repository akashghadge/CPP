#include <bits/stdc++.h>
using namespace std;
int smallSub(int *arr, int n, int target)
{
    // Your code goes here
    int currSum = 0;
    int start = 0;
    int i = 0;
    int subArrayLength = n;
    while (i < n)
    {
        // if we get currSum > target then remove start element from it
        while (currSum > target)
        {
            subArrayLength = min(subArrayLength, (i - start));
            currSum -= arr[start];
            start++;
        }
        currSum += arr[i];
        i++;
    }
    // if last element at last then that should be removed
    while (currSum > target)
    {
        subArrayLength = min(subArrayLength, (i - start));
        currSum -= arr[start];
        start++;
    }
    return subArrayLength;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, M;
    cin >> M;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << smallSub(arr, n, M) << "\n";
    return 0;
}