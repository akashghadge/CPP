/*
Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
Examples: 
 

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.
 
*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
    here native approch is pop last latter and check every time palindrome or not
    time O(n*n)
    use kmp algo and 
    First we concat string by concatenating given string, a special character and reverse of given string then we will get lps array for this concatenated string, recall that each index of lps array represent longest proper prefix which is also suffix. We can use this lps array for solving the problem. 
 



For string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
                   0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
Here we are only interested in the last value of this lps array because it shows us the largest suffix of the reversed string that matches the prefix of the original string i.e these many characters already satisfy the palindrome property. Finally minimum number of character needed to make the string a palindrome is length of the input string minus last entry of our lps array. Pease see below code for better understanding

*/
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
bool isPalindrome(string str)
{
    cout << "str" << en;
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}
int makePalindrome(string str)
{
    // naive approch remove charecters one by one
    int i = 0;
    while (str.size())
    {
        bool val = isPalindrome(str);
        if (val)
        {
            return i;
        }
        str.pop_back();
        i++;
    }
    return 1;
}
vector<int> makeLPS(string str)
{
    vector<int> lps(str.size(), 0);
    int j = 0;
    for (int i = 1; i < str.size(); i++)
    {
        int j = lps[i - 1];
        while (j > 0 and str[i] != str[j])
        {
            j = lps[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}
int makePalindromeOptimise(string str)
{
    string newStr = "";
    newStr.append(str);
    newStr.append("$");
    reverse(str.begin(), str.end());
    newStr.append(str);
    vector<int> lps = makeLPS(newStr);
    printVector(lps);
    return (str.size() - lps.back());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string str;
    while (T--)
    {
        cin >> str;
        // cout << makePalindrome(str) << en;
        cout << makePalindromeOptimise(str) << en;
    }

    return 0;
}