#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void add(priority_queue<int, vector<int>, greater<int>> &left, priority_queue<int> right, int val)
{
    if (right.size() > 0 and val > right.top())
    {
        right.push(val);
    }
    else
    {
        left.push(val);
    }
    if (left.size() - right.size() == 2)
    {
        right.push(left.top());
        left.pop();
    }
    else if (right.size() - left.size() == 2)
    {
        left.push(right.top());
        right.pop();
    }
}
int remove(priority_queue<int, vector<int>, greater<int>> &left, priority_queue<int> right)
{
    if (left.size() == 0 and right.size() == 0)
    {
        return -1;
    }
    else if (left.size() >= right.size())
    {
        int val = left.top();
        left.pop();
        return val;
    }
    else
    {
        int val = right.top();
        right.pop();
        return val;
    }
}
int getMedian(priority_queue<int, vector<int>, greater<int>> &left, priority_queue<int> right)
{
    if (left.size() == 0 and right.size() == 0)
    {
        return -1;
    }
    else if (left.size() >= right.size())
    {
        int val = left.top();
        return val;
    }
    else
    {
        int val = right.top();
        return val;
    }
}

int median(vector<vector<int>> arr)
{
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int> right;
    // 1 add
    // 2 remove (median)
    // 3 peek (median)
    for (auto val : arr)
    {
        switch (val[0])
        {
        case 1:
            add(left, right, val[1]);
            break;
        case 2:
            cout << remove(left, right) << en;
            break;
        case 3:
            cout << getMedian(left, right) << en;
            break;

        default:
            break;
        }

    }
}
int main()
{
    FAST;

    int n;
    cin >> n;
    vector<vector<int>> query(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> query[i][j];
        }
    }
    median(query);
    return 0;
}