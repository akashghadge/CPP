/*
make k non empty subset of array such that on selection is there and here we have to make only those subsets
where all have equal length
eg.
1 2 3 subset 2
1 2 | 3
1 | 2 3
1 3 | 2
but there is no answer here
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
void print(vector<vector<int>> arr)
{
    for (auto list : arr)
    {
        for (auto val : list)
        {
            cout << val << " ";
        }
        cout << " | ";
    }
    cout << en;
}
bool isAns(vector<vector<int>> subsets)
{
    for (auto list : subsets)
    {
        if (list.size() == 0)
            return false;
    }
    int sum = accumulate(subsets[0].begin(), subsets[0].end(), 0);
    for (auto list : subsets)
    {
        int curr_sum = accumulate(list.begin(), list.end(), 0);
        if (curr_sum != sum)
        {
            return false;
        }
    }

    return true;
}
void helper(vector<vector<int>> subsets, vector<int> arr, int curr)
{
    if (curr >= arr.size())
    {
        if (isAns(subsets))
        {
            print(subsets);
        }
        return;
    }

    for (int i = 0; i < subsets.size(); i++)
    {
        if (subsets[i].size() == 0)
        {
            subsets[i].push_back(arr[curr]);
            helper(subsets, arr, curr + 1);
            subsets[i].pop_back();
            break;
        }
        else
        {
            subsets[i].push_back(arr[curr]);
            helper(subsets, arr, curr + 1);
            subsets[i].pop_back();
        }
    }
}
void sol(vector<int> vec, int K)
{
    vector<vector<int>> subsets(K);
    helper(subsets, vec, 0);
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    int K;
    cin >> K;
    sol(vec, K);

    return 0;
}