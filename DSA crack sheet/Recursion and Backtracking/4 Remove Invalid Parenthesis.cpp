/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.


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
/*
here we have string of parenthesis 
e.g 
(()))()

and we need to print string which balanced and have minimum number of removals
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

set<string> st;

vector<string> result;

int min_removal(string s)
{

    int n = s.length();

    stack<char> st;

    for (int i = 0; i < n; i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            continue;
        }

        if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {

            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }

            else
            {
                st.push(s[i]);
            }
        }
    }

    return st.size();
}

void func(string s, int k)
{

    if (k == 0)
    {

        auto itr = find(result.begin(), result.end(), s);

        if (min_removal(s) == 0 && itr == result.end())
        {
            result.push_back(s);
        }

        return;
    }

    if (k < 0)
    {
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            continue;
        }

        string left = s.substr(0, i);
        string right = s.substr(i + 1);

        string temp = left + right;

        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            func(temp, k - 1);
        }
    }
}

vector<string> removeInvalidParentheses(string s)
{

    int k = min_removal(s);

    func(s, k);

    return result;
}
int main()
{
    FAST;
    return 0;
}