/*

*/
#include <bits/stdc++.h>
using namespace std;
void help(string str, int id, int n, string &curr)
{
    if (id == n)
    {
        cout << curr << endl;
        return;
    }
    help(str, id + 1, n, curr);
    curr.push_back(str[id]);
    help(str, id + 1, n, curr);
    curr.pop_back();
}
void subseq(string str)
{
    string curr = "";
    help(str, 0, str.size(), curr);
}
int main()
{
    subseq("akash");
}