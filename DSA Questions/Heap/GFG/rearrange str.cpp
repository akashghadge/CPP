/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same. 
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : 
str = "geeksforgeeks"
Output: 1
Explanation:
All the repeated characters of the 
given string can be rearranged so 
that no adjacent characters in the 
string is equal. Any correct 
rearrangement will show a output of 1.
Example 2:

Input : 
str = "bbbbb"
Output: 0
Explanation : 
Repeated characters in the string cannot 
be rearranged such that there should not 
be any adjacent repeated character.
Your task :
You don't have to read input or print anything. Your task is to complete the function rearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
Note: The generated output is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)

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
string rearrangeString(string str)
{
    //code here
    priority_queue<pair<int, char>> q;
    int charset[256] = {0}, count = str.size();
    string s = "";
    for (int i = 0; i < str.size(); i++)
    {
        charset[str[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (charset[i] > 0)
            q.push({charset[i], i});
    }
    if (q.size() == 1 && count > 1)
        return "-1";
    pair<int, char> prev = {-1, '.'};
    while (count--)
    {
        if (q.top().first == 0)
            return "-1";
        int num = q.top().first;
        char letter = q.top().second;
        s += letter;
        q.pop();
        q.push(prev);
        prev = {num - 1, letter};
    }
    return s;
}
int main()
{
    FAST;

    return 0;
}