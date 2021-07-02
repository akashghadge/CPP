/*
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int lps(string s)
{
    // Your code goes here
    unordered_map<char, int> table;
    vector<int> vec(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {
        if (table.find(s[i]) == table.end())
        {
            table[s[i]] = i;
        }
        else
        {
            vec[i] = table[s[i]] + 1;
            table[s[i]] = i;
        }
    }
    int lastValue = vec[vec.size() - 1] - 1;
    int prefixLen = 0;
    for (int i = vec.size() - 2; i >= 0; i--)
    {
        if (lastValue != vec[i])
        {
            break;
        }
        prefixLen++;
        lastValue--;
    }
    printVector(vec);
    return prefixLen;
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
        cout << lps(str) << en;
    }

    return 0;
}