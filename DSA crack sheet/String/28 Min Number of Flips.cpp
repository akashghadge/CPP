/*
Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

Example 1:

Input:
S = "001"
Output: 1
Explanation: We can flip the 0th bit to 1
to have "101".
â€‹Example 2:

Input: 
S = "0001010111"
Output: 2
Explanation: We can flip the 1st and 8th bit
to have "0101010101".

Your Task:
You don't need to read input or print anything. Your task is to complete the function minFlips() which takes the string S as input and returns the minimum number of flips required.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105

 
*/
// here only two option are there either 0101 or 1010 alternating sequence
// so try both squence and try to compare with it current string how many miss places are there
#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int minFlips(string S)
{
    // your code here
    // with extra space
    // string str1 = "";
    // string str2 = "";
    // for (int i = 0; i < S.size(); i++)
    // {
    //     if ((i & 1) == 0)
    //     {
    //         str1.push_back('0');
    //         str2.push_back('1');
    //     }
    //     else
    //     {
    //         str2.push_back('0');
    //         str1.push_back('1');
    //     }
    // }
    // int change1 = 0;
    // int change2 = 0;
    // for (int i = 0; i < S.size(); i++)
    // {
    //     if (S[i] != str1[i])
    //     {
    //         change1++;
    //     }
    //     else
    //     {
    //         change2++;
    //     }
    // }
    // return min(change1, change2);

    // without extra space
    int change1 = 0;
    int change2 = 0;
    char val = '1';
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != val)
        {
            change1++;
        }
        else
        {
            change2++;
        }
        if ((i & 1) == 0)
        {
            val = '0';
        }
        else
        {
            val = '1';
        }
    }
    return min(change1, change2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}