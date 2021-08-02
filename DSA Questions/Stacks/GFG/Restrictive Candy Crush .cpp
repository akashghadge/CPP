/*
Given a string s and an integer k, the task is to reduce the string by applying the following operation:
Choose a group of k consecutive identical characters and remove them.

The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
k = 2
s = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geeksforgeeks" -> "gksforgks"
Example 2:

Input:
k = 2
s = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() which takes integer k and string s as input parameters and returns the reduced string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 105
1 ≤ k ≤ |s|

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
string Reduced_String(int k, string s)
{
    // Your code goes here
    if (k == 1)
        return "";
    stack<pair<int, char>> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (!st.empty() && st.top().second == s[i])
        {
            int times = st.top().first;
            st.push(make_pair(times + 1, s[i]));
            if (st.top().first == k)
            {
                int temp = k;
                while (temp--)
                {
                    st.pop();
                }
            }
        }
        else
        {
            st.push(make_pair(1, s[i]));
        }
    }
    string res = "";
    while (!st.empty())
    {
        res.push_back(st.top().second);
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    FAST;

    return 0;
}