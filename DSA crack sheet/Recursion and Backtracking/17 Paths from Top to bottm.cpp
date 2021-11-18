/*
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the DSA Self Paced Course at a student-friendly price and become industry ready.  To complete your preparation from learning a language to DS Algo and many more,  please refer Complete Interview Preparation Course.

In case you wish to attend live classes with experts, please refer DSA Live Classes for Working Professionals and Competitive Programming Live for Students.

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths by going right. Do this recursively for each cell encountered.



Following are implementation of the above algorithm. 


*/

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