#include <bits/stdc++.h>
using namespace std;
vector<int> search(vector<vector<int>> m, int target)
{
    vector<int> ans(2, -1);
    if (m.size() == 0)
    {
        return ans;
    }

    int n = m.size();
    int i = 0, j = m[0].size() - 1;
    while (i < m.size() || j >= 0)
    {
        if (m[i][j] == target)
        {
            ans[0] = i;
            ans[1] = j;
            return ans;
        }
        else if (m[i][j] > target)
        {
            j--;
        }
        else if (m[i][j] < target)
        {
            i++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}