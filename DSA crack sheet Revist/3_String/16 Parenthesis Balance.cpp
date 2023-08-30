/*

*/
#include <bits/stdc++.h>
using namespace std;
bool ispar(string str)
{
    stack<char> st;
    for (auto ch : str)
    {
        if (ch == '(' or ch == '{' or ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' and st.size() and st.top() == '(')
        {
            st.pop();
        }
        else if (ch == '}' and st.size() and st.top() == '{')
        {
            st.pop();
        }
        else if (ch == ']' and st.size() and st.top() == '[')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return !st.size();
}

int main()
{
}