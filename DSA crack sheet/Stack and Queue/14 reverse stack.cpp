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
// with o(N) extra space and o(N) time
int rev(stack<int> &st, stack<int> &temp)
{
    if (st.empty())
    {
        return 0;
    }
    int top = st.top();
    temp.push(top);
    st.pop();
    rev(st, temp);
}
// optimise approch
int insert_at_bottom(stack<int> &st, int x)
{
    if (st.size() == 0)
    {
        st.push(x);
    }
    else
    {
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        st.push(a);
    }
}
void revr(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        revr(st);
        insert_at_bottom(st, x);
    }
}

int main()
{
    FAST;
    stack<int> st;
    for (int i = 0; i <= 10; i++)
    {
        st.push(i);
    }
    revr(st);
    while (!st.empty())
    {
        cout << st.top() << en;
        st.pop();
    }

    return 0;
}