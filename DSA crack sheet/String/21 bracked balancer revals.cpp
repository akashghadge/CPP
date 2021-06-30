/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as input parameter and returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 105
*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int countRev(string s)
{
    // your code here
    // stack<char> st;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '{')
    //     {
    //         st.push(s[i]);
    //     }
    //     else
    //     {
    //         if (st.size() && st.top() == '{')
    //         {
    //             st.pop();
    //         }
    //         else
    //         {
    //             st.push(s[i]);
    //         }
    //     }
    // }
    // if ((st.size() & 1) != 0)
    // {
    //     return -1;
    // }
    // int totalSize = st.size();
    // int n = 0;
    // while (st.size() && st.top() == '{')
    // {
    //     // cout << st.top() << en;
    //     n++;
    //     st.pop();
    // }
    // return (n % 2 + totalSize / 2);

    // o(1) space solution
    if ((s.size() & 1) != 0)
    {
        return -1;
    }
    int ob = 0;
    int cb = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
        {
            ob++;
        }
        else
        {
            if (ob == 0)
            {
                cb++;
            }
            else
            {
                ob--;
            }
        }
    }
    int ans = ceil(cb / 2) + ceil(ob / 2);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << countRev(s) << en;
    return 0;
}