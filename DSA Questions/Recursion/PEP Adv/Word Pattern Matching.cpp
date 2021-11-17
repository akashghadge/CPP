/*
We have given word
E.g geeksforgeeks
and we have given pattern 
E.g pep
so map substrings of word to charecters of pattern such that it fits 
p = geeks
e = for

geeks  for  geeks
p       e       p

sample input :-
geeksforgeeks
pep

mzaddyfzaddy
abcb
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
void print(unordered_map<char, string> mp)
{
    for (auto val : mp)
    {
        cout << val.first << " " << val.second << en;
    }
}
void sol(int curr, string pattern, string rem_word, unordered_map<char, string> &mp, string word)
{
    if (curr == pattern.size())
    {
        if (rem_word.size() == 0)
        {
            print(mp);
        }
        return;
    }

    char ch = pattern[curr];
    // if charecter is already map
    if (mp.find(ch) != mp.end())
    {
        string mapped_str = mp[ch];
        if (mapped_str.size() <= rem_word.size())
        {
            string part_word = rem_word.substr(0, mapped_str.size());
            string rem_word_curr = rem_word.substr(mapped_str.size());
            if (part_word == mapped_str)
            {
                sol(curr + 1, pattern, rem_word_curr, mp, word);
            }
        }
    }
    else
    {
        for (int i = 0; i < rem_word.size(); i++)
        {
            string curr_mapping = rem_word.substr(0, i + 1);
            string curr_rem = rem_word.substr(i + 1);
            mp[ch] = curr_mapping;
            sol(curr + 1, pattern, curr_rem, mp, word);
            mp.erase(ch);
        }
    }
}
int main()
{
    FAST;
    string word, pattern;
    cin >> word >> pattern;
    unordered_map<char, string> mp;
    sol(0, pattern, word, mp, word);
    return 0;
}