/*
Given a binary string str of length N, the task is to find the maximum count of substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
Example: 
 

Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010” 
Output: 3 

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int sub(string str)
{
    int n = str.size();
    int c0 = 0;
    int c1 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            c1++;
        }
        else if (str[i] == '0')
        {
            c0++;
        }
        if (c1 == c0)
        {
            c1 = 0;
            c0 = 0;
            cnt++;
        }
    }
    if (c0 != c1)
    {
        return -1;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << sub("011");
    return 0;
}