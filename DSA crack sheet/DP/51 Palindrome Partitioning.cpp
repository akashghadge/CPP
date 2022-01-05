/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as input parameter and returns minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500


*/
// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define vi vector<int>
#define vii vector<vector<int>>

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vii palindroem_table(n, vi(n));
        /*
        here string is palindrome if ends are equal and middle is palindrome i.e table[i+1][j-1];
        */
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; j++, i++)
            {
                if (gap == 0)
                    palindroem_table[i][j] = true;
                else if (gap == 1)
                {
                    if (str[i] == str[j])
                        palindroem_table[i][j] = true;
                }
                else
                {
                    if (str[i] == str[j] && palindroem_table[i + 1][j - 1])
                        palindroem_table[i][j] = true;
                }
            }
        }
    
        // here we fill the table with gap and left right have time complexity of O(n^3)
        vii cuts_req(n, vi(n));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; j++, i++)
            {
                if (palindroem_table[i][j])
                    cuts_req[i][j] = 0;
                else
                {
                    int min_cuts = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int left_req = cuts_req[i][k];
                        int right_req = cuts_req[k + 1][j];
                        min_cuts = min(min_cuts, left_req + right_req);
                    }
                    cuts_req[i][j] = min_cuts + 1;
                }
            }
        }
        return cuts_req[0][n - 1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
