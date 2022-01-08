/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Example:
Input
3
8
20
13
Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the 
two possible permutations but 
these represent the same 
cobmination. Hence output is 1.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function count( ) which takes N as input parameter and returns the answer to the problem.

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000

*/

// { Driver Code Starts
// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    vector<int> table(n + 1, 0);
    table[0] = 1;
    vector<int> p = {3, 5, 10};
    for (auto curr : p)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i - curr >= 0)
            {
                table[i] += table[i - curr];
            }
        }
    }
    return table[n];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
} // } Driver Code Ends