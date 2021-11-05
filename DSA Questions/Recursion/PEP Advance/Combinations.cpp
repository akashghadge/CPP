/*
basically permutaions is selecting different items for positions
and combinations means you have similar items and need to select boxes
so here due to identical items we can only 
have variations over the selection i.e eiter box is selected or not
but no variation on arrange ment 
i.e if 4 box and 2 items there
in permuations              in combinations
1 0 2 0                     i 0 i 0
2 0 1 0                     i 0 i 0

forumla of cobinatios is
nCr = n!/ (n!-r!)* r!

and total combinations of nCr is 2^n 
i.e if we have 4 boxes
then we have total 2^4=16 ways to to combinations bu
those 16 ways are combinations of
4C0 + 4C1 + 4C2 + 4C3 + 4C4
 1  +  4  +  6  +  4  +  1 = 16 ways

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
void sol(int boxes, int index, int totalItems, string ans, int numberOfSelections)
{
    if (index == boxes)
    {
        if (totalItems == numberOfSelections)
            cout << ans << en;
        return;
    }
    sol(boxes, index + 1, totalItems, ans + "_", numberOfSelections);
    sol(boxes, index + 1, totalItems, ans + "I", numberOfSelections + 1);
}

int main()
{
    FAST;
    int N, R;
    cin >> N >> R;
    vector<int> box(N, 0);
    sol(N, 0, R, "", 0);
    return 0;
}