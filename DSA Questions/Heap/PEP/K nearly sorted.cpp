#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void nearlySorted(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int index = 0;
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k + 1; i < arr.size(); i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    FAST;
    int n;
    int k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printVector(arr);
    nearlySorted(arr, k + 1);
    printVector(arr);
    return 0;
}