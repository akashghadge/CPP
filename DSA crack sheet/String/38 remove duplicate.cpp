/*
Given a string S delete the characters which are appearing more than once consecutively.

Example 1:

Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:

Input:
S = aabaa
Output:  aba
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.
 

Your Task:
You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.
 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).
 

Constraints:
1<=|S|<=105
All characters are lowercase alphabets.

*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        if (S.size() < 2)
        {
            return S;
        }
        for (int i = S.size() - 1; i > 0; i--)
        {
            if (S[i] == S[i - 1])
            {
                S.erase(i, 1);
            }
        }
        return S;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}