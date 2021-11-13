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
*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int util(string s, int start, int end, vector<string> &ans)
{
    if (start == end)
    {
        ans.push_back(s);
        return 0;
    }
    for (int i = start; i <= end; i++)
    {
        swap(s[i], s[start]);
        util(s, start + 1, end, ans);
        swap(s[i], s[start]);
    }
}
vector<string> find_permutation(string S)
{
    // Code here there
    vector<string> ans;
    util(S, 0, S.size() - 1, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
}