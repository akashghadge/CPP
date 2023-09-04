/*

*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> searchWord(vector<vector<char>> arr, string word)
{
    // Code here
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> ans;
    vector<int> x = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> y = {0, 0, 1, -1, -1, 1, 1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == word[0])
            {
                bool f = 0;
                for (int dir = 0; dir < 8; dir++)
                {
                    int cn = 0;
                    for (int k = 0; i + (k * x[dir]) < n and i + (k * x[dir]) >= 0 and j + (k * y[dir]) >= 0 and j + (k * y[dir]) < m and k < word.size(); k++)
                    {
                        if (arr[i + (k * x[dir])][j + (k * y[dir])] == word[k])
                            cn++;
                        else
                            break;
                    }
                    // cout<<cn<<" "<<i<<" "<<j<<" "<<dir<<endl;
                    if (cn == word.size())
                    {
                        ans.push_back({i, j});
                        f = 1;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
}