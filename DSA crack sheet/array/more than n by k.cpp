#include <bits/stdc++.h>
using namespace std;
vector<int> more(vector<int> vec, int k)
{
    k = vec.size() / k;
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < vec.size(); i++)
    {
        mp[vec[i]]++;
    }
    for (auto val : mp)
    {
        if (val.second > k)
        {
            ans.push_back(val.first);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}