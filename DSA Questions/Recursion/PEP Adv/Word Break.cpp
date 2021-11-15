/*
here we have list of words
micro soft microsoft hiring hi ring

and one whole string
microsofthiring

so output is using above words to construct the string i.e sentance 

output :-
micro soft hi ring
microsoft hi ring
microsoft hiring
...


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

void helper(string str, string ans, unordered_map<string, bool> &mp)
{
    if (str.size() == 0)
    {
        cout << ans << en;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        string curr_word = str.substr(0, i + 1);
        string rem_word = str.substr(i + 1);
        if (mp.find(curr_word) != mp.end() && mp[curr_word])
        {
            mp[curr_word] = false;
            helper(rem_word, ans + curr_word + " ", mp);
            mp[curr_word] = true;
        }
    }
}
void sol(vector<string> words, string str)
{
    unordered_map<string, bool> mp;
    for (auto str : words)
    {
        mp[str] = true;
    }
    helper(str, "", mp);
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }
    string str;
    cin >> str;
    sol(words, str);

    return 0;
}