/*
bridges with the up and down co-ordinates 
10
10      20
up      down
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Bridge
{
public:
    int top;
    int down;
    Bridge(int top, int down)
    {
        this->top = top;
        this->down = down;
    }
};
int non_overlapping(vector<Bridge *> bridges, int n)
{
    sort(bridges.begin(), bridges.end(),
         [](Bridge *b1, Bridge *b2)
         {
             if (b1->top == b2->top)
                 return b1->down < b2->down;
             return b1->top < b2->top;
         });

    vi lis(n);
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int max_lis = 0;
        for (int j = 0; j < i; j++)
        {
            if (bridges[i]->down <= bridges[j]->down && max_lis < lis[j])
            {
                max_lis = lis[j];
            }
        }
        lis[i] = max_lis;
    }
    return *max_element(lis.begin(), lis.end());
}
int main()
{
    FAST;
    int n;
    vector<Bridge *> bridges;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int top, down;
        cin >> top >> down;
        Bridge *temp = new Bridge(top, down);
        bridges.push_back(temp);
    }
    cout << non_overlapping(bridges, n) << en;
    return 0;
}