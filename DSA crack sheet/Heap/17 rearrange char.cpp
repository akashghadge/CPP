/*

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
struct p
{
    int freq;
    char ch;
    p(char c, int f)
    {
        ch = c;
        freq = f;
    }
};
class compare
{
public:
    bool operator()(p &p1, p &p2)
    {
        return p1.freq < p2.freq;
    }
};
string rearrange(string str)
{
    // init
    unordered_map<char, int> mp;
    for (auto ch : str)
        mp[ch]++;
    priority_queue<p, vector<p>, compare> pq;
    for (auto val : mp)
    {
        p *newp = new p(val.first, val.second);
        pq.push(*newp);
    }

    //is any charecter is greater than half of string
    int l = str.size();
    int upper = (l / 2) + 1; // we are setting the upper limit for the character with greater frequency
                             // if the frequency is greator than the upper limit than we return ""
    if (l % 2 != 0)
    {
        ++upper;
    }
    if (pq.top().freq >= upper)
    { // top element of pq is the character with greatest frequency
        return "";
    }

    string res = "";
    while (!pq.empty())
    {
        p curr = pq.top();
        pq.pop();
        res += curr.ch;
        curr.freq--;
        if (curr.freq > 0)
        {
            pq.push(curr);
        }
    }
    return res;
}
int main()
{
    FAST;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        cout << rearrange(str) << en;
    }
}