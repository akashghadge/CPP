/*
Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Example 1:

Input:
N = 51
Output: AY
Your Task:
Complete the function ExcelColumn() which takes N as input and returns output string.

Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(Log(N))

Constraints:
1 ≤ N ≤ 107


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
class Solution
{
public:
    string ExcelColumn(int n)
    {
        // Your code goes here
        n = n - 1;
        string ans = "";
        ans += char('A' + n % 26);
        n = n / 26;
        while (n > 0)
        {
            ans = char('A' + (n - 1) % 26) + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}