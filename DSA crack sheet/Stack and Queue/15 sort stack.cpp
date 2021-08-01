/*

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class SortedStack
{
    stack<int> s;
    void sort();
};
int insertAccurate(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
    }
    else
    {
        int in = s.top();
        s.pop();
        insertAccurate(s, temp);
        s.push(in);
    }
}
void SortedStack ::sort()
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sort();
    insertAccurate(s, temp);
    return;
}
int main()
{
    FAST;

    return 0;
}