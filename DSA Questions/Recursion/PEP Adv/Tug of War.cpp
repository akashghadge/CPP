/*
here we have array of n elements 
task is divide all elements in two arrays 
if n is even subsets contains n/2 elements 
if n is odd -"- n/2 and n/2+1

such that differnce of sum is minimum

@this question is incomplete 
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
void helper(int curr, vi arr, vi slot1, vi slot2, int *min_diff)
{
    if (curr >= arr.size())
    {
        int size1 = slot1.size();
        int size2 = slot2.size();
        int diff = abs(size2 - size1);

        if (diff < 1)
        {
            int sum1 = accumulate(slot1.begin(), slot1.end(), 0);
            int sum2 = accumulate(slot2.begin(), slot2.end(), 0);
            int curr_diff = sum1 - sum2;
            *min_diff = min(*min_diff, curr_diff);
        }
    }
    slot1.push_back(arr[curr]);
    helper(curr + 1, arr, slot1, slot2, min_diff);
    slot1.pop_back();
    slot2.push_back(arr[curr]);
    helper(curr + 1, arr, slot1, slot2, min_diff);
    slot2.pop_back();
}
void sol(vi arr)
{
    vi slot1;
    vi slot2;
    int min_diff = INT_MAX;
    helper(0, arr, slot1, slot2, &min_diff);
    cout << min_diff << en;
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sol(arr);
}