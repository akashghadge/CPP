#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vector<int> kthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> kth;
    for (auto val : arr)
    {
        if (kth.size() >= k)
        {
            if (kth.top() < val)
            {
                kth.pop();
                kth.push(val);
            }
        }
        else
        {
            kth.push(val);
        }
    }
    vector<int> res; 
    while (!kth.empty())
    {
        res.push_back(kth.top());
        kth.pop();
    }

    return res;
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

    vector<int> res = kthLargest(arr, k);
    printVector(res);
    return 0;
}