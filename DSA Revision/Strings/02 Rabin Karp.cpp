/*

*/
#include <bits/stdc++.h>
using namespace std;
const int POW_LEN = 1e5 + 10;
vector<int> powers(POW_LEN, 1);
const int prime = 31;
const int mod = 1e9 + 7;
void init()
{
    powers[0] = 1;
    for (int i = 1; i < POW_LEN; i++)
    {
        powers[i] = (powers[i - 1] * 1LL * prime) % mod;
    }
}
vector<int> rabin(string str, string pat)
{
    vector<int> ans;
    int i = 0;
    int patHash = 0;
    for (auto ch : pat)
    {
        patHash = (patHash + (((ch - 'a' + 1) * powers[i]) % mod)) % mod;
        i++;
    }
    int p = pat.size();
    int s = str.size();
    vector<int> string_hash(s + 1, 0);
    for (int i = 0; i < s; i++)
    {
        char ch = str[i];
        string_hash[i + 1] = (string_hash[i] + (((ch - 'a' + 1) * powers[i]) % mod)) % mod;
    }
    for (int i = 0; i + p - 1 < s; i++)
    {
        int curr_hash = (string_hash[i + p] - string_hash[i] + mod) % mod;
        if (curr_hash == ((patHash * powers[i]) % mod))
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    init();
    for (auto val : rabin("aaaa", "aa"))
    {
        cout << val << " ";
    }
}