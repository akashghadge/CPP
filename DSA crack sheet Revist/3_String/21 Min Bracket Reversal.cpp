/*

*/
#include <bits/stdc++.h>
using namespace std;
int countRev(string str)
{
    // your code here
    if (str.size() % 2 == 1)
        return -1;
    int o = 0, c = 0;
    for (auto val : str)
    {
        if (val == '{')
            o++;
        else
        {
            if (o != 0)
                o--;
            else
                c++;
        }
    }
    return ceil((double)o / 2) + ceil((double)c / 2);
}
int main()
{
}