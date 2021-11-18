/*
Shibam is asked to organise a Tug of War competition for which he has to create two groups of people.
There are N people who are participating in the game who are numbered from 1 to N. The i-th person has a strength of i units. Shibam has to divide the people into two groups A and B such that the absolute value of the difference of total strength of the two groups is as low as possible.
The total strength of a group is the sum of the strengths of each person in that group.
Help Shibam find the minimum absolute difference.
Input
First line will contain T, number of testcases. Then the testcases follow.
Each test case contains an integer N, the number of people participating.
Output
For each test case print an integer,the minimum value of the absolute difference.

Constraints
1 <= T <= 10^5
1 <= N <= 10^9
Example
Input:
1
3
Output:
0

Explanation

Group A will contain persons 1 and 2. Group B will containg person 3. So ans = |(1+2)-(3)| = 0.
Author:	6★himkha_100
Tags:	himkha_100

Problem level:	Unavailable
Date Added:	23-01-2019
Time Limit:	1 secs
Source Limit:	50000 Bytes
Languages:	CPP14, C, JAVA, PYTH 3.6, PYTH, PYP3, CS2, ADA, PYPY, TEXT, PAS fpc, NODEJS, RUBY, PHP, GO, HASK, TCL, PERL, SCALA, LUA, kotlin, BASH, JS, LISP sbcl, rust, PAS gpc, BF, CLOJ, D, CAML, FORT, ASM, swift, FS, WSPC, LISP clisp, SCM guile, PERL6, ERL, CLPS, ICK, NICE, PRLG, ICON, COB, SCM chicken, PIKE, SCM qobi, ST, NEM
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
void helper(int curr, int total, vector<int> group1, vector<int> group2, int *min_ans)
{
    if (curr > total)
    {
        int sum1 = accumulate(group1.begin(), group1.end(), 0);
        int sum2 = accumulate(group2.begin(), group2.end(), 0);
        int diff = abs(sum1 - sum2);
        *min_ans = min(*min_ans, diff);
        return;
    }
    group1.push_back(curr);
    helper(curr + 1, total, group1, group2, min_ans);
    group1.pop_back();
    group2.push_back(curr);
    helper(curr + 1, total, group1, group2, min_ans);
    group2.pop_back();
}
void sol(int N)
{
    vector<int> group1;
    vector<int> group2;
    int min_ans = INT_MAX;
    helper(1, N, group1, group2, &min_ans);
    cout << min_ans << en;
}
int main()
{
    // FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        // simple solution
        int sum = (N + 1) * N / 2;
        cout << sum % 2 << endl;
        // sol(N);
    }

    return 0;
}