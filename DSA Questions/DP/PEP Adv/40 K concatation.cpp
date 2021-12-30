/*
this is modification of kadens algo
we have arr and k number
arr have k copies continuously
1 2 3
3
then
1 2 3 1 2 3 1 2 3
find the max sum subarray 
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int kaden(vi arr, int n)
{
    int ans = 0;
    int curr_ans = 0;
    for (auto val : arr)
    {
        if (curr_ans <= 0)
        {
            curr_ans = 0;
        }
        curr_ans += val;
        ans = max(ans, curr_ans);
    }
    return ans;
}
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int k_concatenation(vi arr, int n, int k)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (k == 1)
    {
        return kaden(arr, n);
    }
    else if (sum < 0)
    {
        arr.insert(arr.end(), arr.begin(), arr.end());
        return kaden(arr, n + n);
    }
    else
    {
        arr.insert(arr.end(), arr.begin(), arr.end());
        return kaden(arr, n + n) + (k - 2) * sum;
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << k_concatenation(arr, N, k) << en;
    return 0;
}