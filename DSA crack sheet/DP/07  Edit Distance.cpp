/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation to convert the string s to string t. 


Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)


Constraints:
1 ≤ Length of both strings ≤ 100
Both the strings are in lowercase.


*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int min_custom(int x, int y, int z)
    {
        int temp = min(x, y);
        return min(temp, z);
    }
    int editDistance(string str1, string str2)
    {
        // Code here
        int m = str1.size();
        int n = str2.size();
        int dp[m + 1][n + 1];

        // Fill d[][] in bottom up manner
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // If first string is empty, only option is to
                // insert all characters of second string
                if (i == 0)
                    dp[i][j] = j; // Min. operations = j

                // If second string is empty, only option is to
                // remove all characters of second string
                else if (j == 0)
                    dp[i][j] = i; // Min. operations = i

                // If last characters are same, ignore last char
                // and recur for remaining string
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                // If the last character is different, consider
                // all possibilities and find the minimum
                else
                    dp[i][j] = 1 + min_custom(dp[i][j - 1],      // Insert
                                              dp[i - 1][j],      // Remove
                                              dp[i - 1][j - 1]); // Replace
            }
        }

        return dp[m][n];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends