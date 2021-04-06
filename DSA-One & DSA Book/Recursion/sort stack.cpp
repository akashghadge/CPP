#include <iostream>
using namespace std;
#include "stack"
#include "vector"
#include "algorithm"
int sort_stack(stack<int> &st, vector<int> &ans, int currentLevel)
{
    if (st.empty())
    {
        sort(ans.begin(), ans.end());
        return 0;
    }
    ans.push_back(st.top());
    st.pop();
    sort_stack(st, ans, currentLevel + 1);
    st.push(ans[ans.size() - currentLevel-1]);
    return 0;
} 
int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(6);
    st.push(5);
    st.push(4);
    vector<int> ans;
    sort_stack(st, ans, 0);
    while (!st.empty())
    {
        cout << "Stack elemnt : " << st.top() << endl;
        st.pop();
    }
}