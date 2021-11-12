/*
it is basic permutation which have formula nPr
i.e 
consider n box and r items
so first item have n options
second have n-1 
up to so on
last have  n-r-1 options
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
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void sol(vector<int> &box, int index, int items)
{
    if (index > items)
    {
        printVector(box);
        return;
    }
    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] == 0)
        {
            box[i] = index;
            sol(box, index + 1, items);
            box[i] = 0;
        }
    }
}
int main()
{
    FAST;
    int N;
    int R;
    cin >> N >> R;
    vector<int> box(N, 0);
    sol(box, 1, R);
    return 0;
}