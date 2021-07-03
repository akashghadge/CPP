/*
Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion? 
Example: 

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink 


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << en;
}
string util(vector<vector<string>> &stringList, string currentString, int index, vector<string> &ans)
{
    if (index == stringList.size())
    {
        currentString += '\n';
        ans.push_back(currentString);
        return "";
    }
    for (int i = 0; i < stringList[index].size(); i++)
    {
        string str = currentString + " " + stringList[index][i];
        util(stringList, str, index + 1, ans);
    }
    return "";
}

vector<string> sol(vector<vector<string>> &stringList)
{
    vector<string> ans;
    util(stringList, "", 0, ans);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N;
        vector<vector<string>> stringList;
        for (int i = 0; i < N; i++)
        {
            cin >> M;
            vector<string> list(M);
            for (int i = 0; i < M; i++)
            {
                cin >> list[i];
            }
            stringList.push_back(list);
        }
        vector<string> ans = sol(stringList);
        printVector(ans);
    }

    return 0;
}