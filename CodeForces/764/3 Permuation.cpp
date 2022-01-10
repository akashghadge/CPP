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
template <class printVal>
void printVector(vector<printVal> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int sol(vi arr, int n)
{
    sort(arr.begin(), arr.end());
    unordered_map<char, int> mp;
    for (int i = 1; i <= n; i++)
        mp[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
            continue;
        while (arr[i] > n)
        {
            arr[i] = arr[i] / 2;
        }
    }
    sort(arr.begin(), arr.end());
    printVector(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return false;
    }
    return true;
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vi arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << "Test Case :" << en;
        sol(arr, N) ? cout << "YES" : cout << "NO";
        cout << en;
    }

    return 0;
}