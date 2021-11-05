/*
in this question we going to solve it by using permutation 1 concept i.e
it is basic permutation which have formula nPr
i.e 
consider n box and r items
so first item have n options
second have n-1 
up to so on
last have  n-r-1 options

but expect the above approch we need to cut r! options so we get only selection variations not selection + arrangment
so we try to eliminate it by running the loop from of options only by current selected box
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
void print(vector<bool> box)
{
    for (auto val : box)
    {
        val ? cout << "I" : cout << "_";
    }
    cout << en;
}
void sol(vector<bool> box, int curr_index, int total_selection, int curr_selected)
{
    if (curr_index >= total_selection)
    {
        print(box);
        return;
    }
    for (int i = curr_selected + 1; i < box.size(); i++)
    {
        if (!box[i])
        {
            box[i] = true;
            sol(box, curr_index + 1, total_selection, i);
            box[i] = false;
        }
    }
}
int main()
{
    FAST;
    int N, C;
    cin >> N >> C;
    vector<bool> box(N, false);
    sol(box, 0, C, -1);
    return 0;
}