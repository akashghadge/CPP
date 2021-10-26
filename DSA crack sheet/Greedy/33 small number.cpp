/*
The task is to find the smallest number with given sum of digits as S and number of digits as D.

 

Example 1:

Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
 

Example 2:

Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function smallestNumber() which takes the two integers S and D and returns a string which is the smallest number if possible, else return "-1".

 

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ S ≤ 100
1 ≤ D ≤ 6

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
string smallestNumber(int S, int D)
{
    // code here
    if (S == 0)
    {
        if (D == 1)
            return "0";
        else
            return "-1";
    }
    if (S > D * 9)
        return "-1";

    S -= 1;
    string res = "";
    res.insert(res.begin(), D, '0');
    for (int i = D - 1; i > 0; i--)
    {
        if (S > 9)
        {
            res[i] = '9';
            S -= 9;
        }
        else
        {
            res[i] = '0' + S;
            S = 0;
        }
    }
    res[0] = '1' + S;
    return res;
}
int main()
{
    FAST;

    return 0;
}