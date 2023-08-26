/*

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>> arr, int r, int c)
{
    // code here
    vector<int> ans;
    int rt = 0, rb = r - 1, cl = 0, cr = c - 1;
    while (rt <= rb and cl <= cr)
    {
        // last row
        if (rt == rb)
        {
            for (int i = cl; i <= cr; i++)
            {
                ans.push_back(arr[rt][i]);
            }
            break;
        }
        // last column
        if (cl == cr)
        {
            for (int i = rt; i <= rb; i++)
            {
                ans.push_back(arr[i][cl]);
            }
            break;
        }

        // hor
        for (int i = cl; i <= cr; i++)
        {
            ans.push_back(arr[rt][i]);
        }
        ans.pop_back();
        for (int i = rt; i <= rb; i++)
        {
            ans.push_back(arr[i][cr]);
        }
        ans.pop_back();
        for (int i = cr; i >= cl; i--)
        {
            ans.push_back(arr[rb][i]);
        }
        ans.pop_back();
        for (int i = rb; i >= rt; i--)
        {
            ans.push_back(arr[i][cl]);
        }
        ans.pop_back();
        rt++, rb--, cl++, cr--;
    }
    return ans;
}

int main()
{
}