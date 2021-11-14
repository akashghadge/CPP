/*
here we have n words
n=4
dog cat dad good
and charecters can ussed
k=9
a b c d d d g o o
and score of  a to z chars
find the max score such that 
subsets made by this n words should conly contains k charecters limit and have max score according to a to z chart

example input 
4
dog cat dad good
9
a b c d d d g o o
1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 
0 0 0 0 0 0
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
bool isValid(vector<string> curr_ans, unordered_map<char, int> freq)
{
    for (auto str : curr_ans)
    {
        for (auto ch : str)
        {
            if (freq.find(ch) != freq.end() && freq[ch] > 0)
                freq[ch]--;
            else
                return false;
        }
    }
    return true;
}
void helper(int curr, vector<string> words, unordered_map<char, int> freq, vector<vector<string>> &subsets, vector<string> curr_ans)
{
    if (curr >= words.size())
    {
        if (isValid(curr_ans, freq))
        {
            subsets.push_back(curr_ans);
        }
        return;
    }
    helper(curr + 1, words, freq, subsets, curr_ans);
    curr_ans.push_back(words[curr]);
    helper(curr + 1, words, freq, subsets, curr_ans);
}
void sol(vector<string> words, unordered_map<char, int> freq, unordered_map<char, int> score)
{
    vector<vector<string>> subsets;
    vector<string> curr;
    helper(0, words, freq, subsets, curr);

    int max_score = INT_MIN;
    for (auto subset : subsets)
    {
        int curr_score = 0;
        for (auto str : subset)
        {
            for (auto ch : str)
            {
                curr_score += score[ch];
            }
        }
        max_score = max(curr_score, max_score);
    }
    cout << max_score << en;
}
int main()
{
    FAST;
    int n, k;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    cin >> k;
    unordered_map<char, int> freq;
    for (int i = 0; i < k; i++)
    {
        char ch;
        cin >> ch;
        freq[ch]++;
    }
    unordered_map<char, int> score;
    for (int i = 0; i < 26; i++)
    {
        int temp;
        cin >> temp;
        score['a' + i] = temp;
    }

    sol(words, freq, score);

    return 0;
}