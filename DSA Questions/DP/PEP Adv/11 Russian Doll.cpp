/*
here we have height and width of envelopes 
and we need to find how much envelopes we can pack
n envelopes 

sample test
11
17 5
26 18
25 34
48 84
63 72
42 86
9 55
4 70
21 45
68 76
58 51
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
class Envelope
{
public:
    int height;
    int width;
    Envelope(int height, int width)
    {
        this->height = height;
        this->width = width;
    }
};
int russian_doll(vector<Envelope *> envelopes, int n)
{
    sort(envelopes.begin(), envelopes.end(),
         [](Envelope *e1, Envelope *e2)
         {
             if (e1->height == e2->height)
                 return e1->width < e2->width;
             return e1->height < e2->height;
         });
    vi lis(n);
    for (int i = 0; i < n; i++)
    {
        int max_lis = 0;
        for (int j = 0; j < i; j++)
        {
            if (envelopes[i]->width >= envelopes[j]->width && max_lis < lis[j])
                max_lis = lis[j];
        }
        lis[i] = max_lis + 1;
    }
    return *max_element(lis.begin(), lis.end());
}
int main()
{
    FAST;
    int n;
    cin >> n;
    vector<Envelope *> envelopes;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        Envelope *temp = new Envelope(h, w);
        envelopes.push_back(temp);
    }
    cout << russian_doll(envelopes, n) << en;

    return 0;
}