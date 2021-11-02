/*
We have n number of stairs and have [1,2,3] steps to take to react end print all possible paths
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
vector<int> steps = {1, 2, 3};
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << en;
    }
    cout << endl;
}
vector<string> sol(int num)
{
    vector<string> res;
    if (num == 0)
    {
        res.push_back("");
        return res;
    }
    else if (num < 0)
    {
        return res;
    }

    vector<string> path1 = sol(num - 1);
    vector<string> path2 = sol(num - 2);
    vector<string> path3 = sol(num - 3);

    for (auto path : path1)
        res.push_back('1' + path);
    for (auto path : path2)
        res.push_back('2' + path);
    for (auto path : path3)
        res.push_back('3' + path);

    return res;
}
int main()
{
    FAST;
    printVector(sol(10));
    return 0;
}