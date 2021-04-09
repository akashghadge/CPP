#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
vector<char> rep(string s)
{
    vector<char> ans;
    if (s.size() == 0)
    {
        return ans;
    }
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    for (auto x : m)
    {
        if (x.second >= 2)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
}
void printVector(vector<char> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector<char> ans = rep("akashsureshghadge");
    printVector(ans);
}

// time would be o(nlogn)
// space would be o(a); where a is distinct elements