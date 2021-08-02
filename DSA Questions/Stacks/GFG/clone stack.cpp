/*
Given elements of a stack, clone the stack without using extra space.


Example 1:

Input:
N = 10
st[] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 7}
Output:
1 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function clonestack() which takes the input stack st[], an empty stack cloned[], you have to clone the stack st into stack cloned.
The driver code itself prints 1 in the output if the stack st is cloned properly and prints 0 otherwise.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)
 

Constraints:
1 <= N <= 1000
1<= st[i] <= 105


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
class Solution
{
public:
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
    void clonestack(stack<int> st, stack<int> &cloned)
    {
        //code here
        // this will also work
        // st.swap(cloned);
        revr(st);
        while (!st.empty())
        {
            cloned.push(st.top());
            st.pop();
        }
    }
};
int main()
{
    FAST;

    return 0;
}
