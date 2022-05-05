#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
class Sort
{
public:
    void BubbleSort(vi &arr, int n, bool flag = true)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (flag)
                {
                    if (arr[i] >= arr[j])
                        swap(arr[i], arr[j]);
                }
                else
                {
                    if (arr[i] <= arr[j])
                        swap(arr[i], arr[j]);
                }
    }
    void BubbleSort(vi &arr, int n, int start, int end, bool flag = true)
    {
        start = max(0, start);
        end = min(n, end);
        for (int i = start; i < end; i++)
            for (int j = start; j < end; j++)
                if (flag)
                {
                    if (arr[i] >= arr[j])
                        swap(arr[i], arr[j]);
                }
                else
                {
                    if (arr[i] <= arr[j])
                        swap(arr[i], arr[j]);
                }
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
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Sort s;
    s.BubbleSort(arr, N, false);
    s.printVector(arr);
    s.BubbleSort(arr, N, 0, 5);
    s.printVector(arr);
}