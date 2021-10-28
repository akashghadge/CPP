/*
Snackdown 2019 is coming! There are two rounds (round A and round B) after the qualification round. From both of them, teams can qualify to the pre-elimination round. According to the rules, in each of these two rounds, teams are sorted in descending order by their score and each team with a score greater or equal to the score of the team at the K=1500-th place advances to the pre-elimination round (this means it is possible to have more than K qualified teams from each round in the case of one or more ties after the K-th place).

Today, the organizers ask you to count the number of teams which would qualify for the pre-elimination round from round A for a given value of K (possibly different from 1500). They provided the scores of all teams to you; you should ensure that all teams scoring at least as many points as the K-th team qualify.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers S1,S2,…,SN.
Output
For each test case, print a single line containing one integer — the number of qualified teams.

Constraints
1≤T≤1,000
1≤K≤N≤105
1≤Si≤109 for each valid i
the sum of N for all test cases does not exceed 106
Example Input
2
5 1
3 5 2 4 5
6 4
6 5 4 3 2 1
Example Output
2
4

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
int arr[100010];
int sol(int N, int K)
{
    sort(arr, arr + N, greater<int>());
    int marker = arr[K - 1];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty() && pq.top() < marker)
        pq.pop();

    return pq.size();
}
int main()
{
    FAST;
    int T;
    cin >> T;
    int N, K;
    while (T--)
    {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << sol(N, K) << en;
    }

    return 0;
}