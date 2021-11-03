/*
here we can travel h[] and v[] and d[] options
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
vector<string> sol(int sx, int sy, int dx, int dy)
{
    vector<string> res;
    if (sx == dx and sy == dy)
    {
        res.push_back("");
        return res;
    }
    else if (sx > dx and sy > dy)
    {
        return res;
    }
    vector<string> hPaths;
    vector<string> vPaths;
    vector<string> dPaths;
    for (int h = 1; h <= (dx - sx); h++)
    {
        int jump = h;
        vector<string> tempRes;
        if (sx < dx)
        {
            tempRes = sol(sx + jump, sy, dx, dy);
            hPaths.insert(hPaths.end(), tempRes.begin(), tempRes.end());
        }
    }
    for (int v = 1; v <= (dy - sy); v++)
    {
        int jump = v;
        vector<string> tempRes;
        if (sy < dy)
        {
            tempRes = sol(sx, sy + jump, dx, dy);
            vPaths.insert(vPaths.end(), tempRes.begin(), tempRes.end());
        }
    }
    for (int d = 1; d <= (dx - sx) && d <= (dy - sy); d++)
    {
        int jump = d;
        vector<string> tempRes;
        if (sy < dy && sx < dx)
        {
            tempRes = sol(sx + jump, sy + jump, dx, dy);
            dPaths.insert(dPaths.end(), tempRes.begin(), tempRes.end());
        }
    }

    for (auto path : hPaths)
        res.push_back("h" + path);
    for (auto path : vPaths)
        res.push_back("v" + path);
    for (auto path : dPaths)
        res.push_back("d" + path);
    return res;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    FAST;
    int n, m;
    cin >> m >> n;
    vector<string> res = sol(1, 1, m, n);
    printVector(res);
    return 0;
}