/*
Given a string S. The task is to print all permutations of a given string.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5

*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
string util(string str, int i, set<string> &ans)
{
    if (i == str.size())
    {
        ans.insert(str);
        return "";
    }
    for (int k = 0; k < str.size(); k++)
    {
        string temp = str;
        swap(temp[i], temp[k]);
        util(temp, i + 1, ans);
    }
    return "";
}
set<string> permu(string str)
{
    set<string> ans;
    util(str, 0, ans);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    // cout << "Hello" << endl;
    set<string> per = permu(str);
    cout << "Ans" << en;
    cout << per.size() << en;
    for (string s : per)
    {
        cout << s << en;
    }

    return 0;
}