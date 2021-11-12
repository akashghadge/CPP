/*
Int the first approch we have used to approch of
making decisions on levels okay
it is basic permutation which have formula nPr
i.e 
consider n box and r items
so first item have n options
second have n-1 
up to so on
last have  n-r-1 options


and for this approch we have make the permutation using combinations
i.e in combination we have either selected or not selected
i.e making box empty or selecting it

but in this time we have total 1 + r options to explore 1 is for empty and r for options need to select i.e here we can say selection + arrangment
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
void sol(int curr_box, int total_box, vector<bool> itemsSelected, int selections, int total_selections, string ans)
{
    if (curr_box >= total_box)
    {
        if (selections == total_selections)
        {
            cout << ans << en;
        }
        return;
    }

    for (int i = 0; i < total_selections; i++)
    {
        if (!itemsSelected[i])
        {
            itemsSelected[i] = true;
            sol(curr_box + 1, total_box, itemsSelected, selections + 1, total_selections, ans + to_string(i + 1));
            itemsSelected[i] = false;
        }
    }
    sol(curr_box + 1, total_box, itemsSelected, selections, total_selections, ans + to_string(0));
}
int main()
{
    FAST;
    int N, C;
    cin >> N >> C;
    vector<bool> itemsSelected(C, false);
    sol(0, N, itemsSelected, 0, C, "");
    return 0;
}