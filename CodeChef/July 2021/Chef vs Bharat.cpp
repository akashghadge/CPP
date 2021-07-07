/*
Chef and his friend Bharat have decided to play the game "The Chefora Spell".

In the game, a positive integer N (in decimal system) is considered a "Chefora" if the number of digits d is odd and it satisfies the equation
N=∑i=0d−1Ni⋅10i,
where Ni is the i-th digit of N from the left in 0-based indexing.

Let Ai denote the i-th smallest Chefora number.

They'll ask each other Q questions, where each question contains two integers L and R. The opponent then has to answer with

(∏i=L+1R(AL)Ai)mod109+7.
Bharat has answered all the questions right, and now it is Chef's turn. But since Chef fears that he could get some questions wrong, you have come to his rescue!

Input
The first line contains an integer Q - the number of questions Bharat asks.
Each of the next Q lines contains two integers L and R.
Output
Print Q integers - the answers to the questions on separate lines.

Constraints
1≤Q≤105
1≤L<R≤105
Subtasks
Subtask #1 (30 points):
1≤Q≤5⋅103
1≤L<R≤5⋅103

Subtask #2 (70 points): Original constraints

Sample Input
2
1 2
9 11
Sample Output
1
541416750
Explanation
For the first question:
(A1)A2=12=1.
For the second question:
(A9)A10⋅(A9)A11=9101⋅9111≡541416750(mod109+7).

*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/* getting all chefora numbers */
const ll CHEF = 1e5 + 1;
vector<ll> chefora(CHEF, 0);
vector<ll> cheforSum(CHEF, 0);
// for getting power in logn time
ll powerLog(ll base, ll p)
{
    long long res = 1;
    long long M = 1e9 + 7;
    while (p > 0)
    {
        if (p & 1)
            res = ((res % M) * (base % M)) % M;

        p = p >> 1;
        base = ((base % M) * (base % M)) % M;
    }
    return res;
}
// actual solution
ll solOp(ll L, ll R)
{
    return powerLog((chefora[L]), (cheforSum[R] - cheforSum[L]));
}
ll getChefora(ll num)
{
    ll temp = num;
    if (num < 10)
    {
        return num;
    }
    num = num / 10;
    while (num != 0)
    {
        temp = temp * 10 + num % 10;
        num /= 10;
    }
    return temp;
}
void init()
{
    for (int i = 1; i < 100001; i++)
    {
        chefora[i] = getChefora(i);
        cheforSum[i] = cheforSum[i - 1] + chefora[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // init chefora
    init();
    cout << chefora[100000] << en;
    int Q;
    cin >> Q;
    ll L, R;
    while (Q--)
    {
        cin >> L >> R;
        // cout << chefora[L] << en;
        cout << solOp(L, R) << en;
    }
    return 0;
}