#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
/*
1 2 3 4 5 6 
1 4 2 5 3 6
*/
void divideHalf(queue<int> &q)
{
    int size = q.size();
    int curr = 0;
    queue<int> first;
    queue<int> last;
    while (curr < size / 2)
    {
        first.push(q.front());
        q.pop();
        curr++;
    }
    while (!q.empty())
    {
        last.push(q.front());
        q.pop();
    }
    int i = 0;
    while (!first.empty() && !last.empty())
    {
        if ((i & 1) == 0)
        {
            q.push(first.front());
            first.pop();
        }
        else
        {
            q.push(last.front());
            last.pop();
        }
        i++;
    }
    while (!first.empty())
    {
        q.push(first.front());
        first.pop();
    }
    while (!last.empty())
    {
        q.push(last.front());
        last.pop();
    }
}
int main()
{
    FAST;
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    divideHalf(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}