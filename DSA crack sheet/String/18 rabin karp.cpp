/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

Example 1:

Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
â€‹Example 2:

Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string S and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string S. 


Expected Time Complexity: O(|S|*|pat|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
1<=|pat|<|S|


*/
#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
const int M = 1e9 + 7;
const int POWLEN = 1e5 + 7;
int P = 31;
// powers of number
vector<ll> powers(POWLEN);
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void initPow()
{
    powers[0] = 1;
    for (int i = 1; i < POWLEN; i++)
    {
        powers[i] = ((powers[i - 1] % M) * (P)) % M;
    }
}
vector<int> rabin(string str, string pattern)
{
    vector<int> ans;
    int T = str.size();
    int S = pattern.size();
    vector<ll> hMain(T + 1, 0);

    // calculate for main string
    for (int i = 0; i < T; i++)
    {
        hMain[i + 1] = (hMain[i] + (str[i] - 'a' + 1) * powers[i]) % M;
    }

    // getting whole pattern hash
    ll hashOfPattern = 0;
    for (int i = 0; i < S; i++)
    {
        hashOfPattern = (hashOfPattern + (pattern[i] - 'a' + 1) * powers[i]) % M;
    }

    for (int i = 0; i + S - 1 < T; i++)
    {
        ll currHash = (hMain[i + S] - hMain[i] + M) % M;
        if (currHash == (hashOfPattern * powers[i]) % M)
        {
            ans.push_back(i + 1);
        }
    }
    if (ans.size() == 0)
    {
        ans.push_back(-1);
        return ans;
    }
    else
    {
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string str, pattern;
    initPow();
    while (T--)
    {
        cin >> str >> pattern;
        vector<int> ans = rabin(str, pattern);
        printVector(ans);
    }

    return 0;
}