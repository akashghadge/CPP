/*
Given a String. Reverse each word in it where the words are separated by dots.

Example 1:

Input:
S = "i.like.this.program.very.much"
Output: i.ekil.siht.margorp.yrev.hcum
Explanation: The words "i", "like",
"this", "program", "very", "much"
are all reversed.
â€‹Example 2:

Input: 
S = "pqr.mno"
Output: rqp.onm
Explanation: Both "pqr" and "mno" are
reversed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function reverseWords() which takes the string S as input and returns the resultant string by reversing all the words separated by dots.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).


Constraints:
1<=|S|<=105


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
class Sol
{
public:
    string reverseWords(string s)
    {
        //code here.
        stack<char> st;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                while (!st.empty())
                {
                    res.push_back(st.top());
                    st.pop();
                }
                res.push_back(s[i]);
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (st.size() != 0)
        {
            while (!st.empty())
            {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};
int main()
{
    FAST;

    return 0;
}