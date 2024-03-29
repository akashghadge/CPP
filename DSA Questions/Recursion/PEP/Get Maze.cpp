/*
start point in (0,0) and end point is (m,n) matrix you need to get all paths to end point
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
template <class vecInput>
void printVector(vector<vecInput> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << en;
    }
    cout << en;
}
vector<string> sol(int m, int n)
{
    // bottom up approch
    vector<string> res;
    if (n == 1 && m == 1)
    {
        res.push_back("");
        return res;
    }
    else if (m < 0 or n < 0)
    {
        return res;
    }

    vector<string> hPath = sol(m - 1, n);
    vector<string> vPath = sol(m, n - 1);
    for (auto path : hPath)
        res.push_back("h" + path);
    for (auto path : vPath)
        res.push_back("v" + path);

    return res;
}
vector<string> solTopDown(int srx, int sry, int dsx, int dsy)
{
    vector<string> res;
    if (srx == dsx and sry == dsy)
    {
        res.push_back("");
        return res;
    }
    else if (srx > dsx and sry > dsy)
    {
        return res;
    }
    vector<string> hPath;
    vector<string> vPath;
    if (srx < dsx)
    {
        hPath = solTopDown(srx + 1, sry, dsx, dsy);
    }
    if (sry < dsy)
    {
        vPath = solTopDown(srx, sry + 1, dsx, dsy);
    }
    for (auto path : hPath)
        res.push_back("h" + path);
    for (auto path : vPath)
        res.push_back("v" + path);

    return res;
}
int main()
{
    FAST;
    int n, m;
    cin >> m >> n;
    vector<string> res = sol(m, n);
    cout << "Bottom Up Approch :" << en;
    printVector(res);
    cout << "Top Down Approch :" << en;
    res = solTopDown(1, 1, m, n);
    printVector(res);
    return 0;
}