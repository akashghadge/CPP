/*
here we have two strings 
a and b
find the longest common subsequence between them
*/
/*
# Simple approach
we can find all subsequence and then just using two for loops check longest same common subsequence 

# DP approach
here consider this math
what is subsequence of string 
total subseq = (_ + (n-1 sub)) +  (char + (n-1 sub));
so for both string looping over all subsequence we can say that 

(_ + (n-1 sub1))        *        (_ + (m-1 sub2))
(char1 + (n-1 sub1))    *        (char2 + (m-1 sub2)) 

so it is product of both things
so we formulate this as
if c1 == c2
then ans will be from the last product group i.e (char1 + (n-1 sub1)) * (char2 + (m-1)sub2) ;
else
it will max of the other 3 note 3 groups  
*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int longest_common_sub(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vii dp(n + 1, vi(m + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            char first_char = str1[i];
            char second_char = str2[j];
            if (first_char == second_char)
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    FAST;
    string str1, str2;
    cin >> str1 >> str2;
    cout << longest_common_sub(str1, str2) << en;
    return 0;
}