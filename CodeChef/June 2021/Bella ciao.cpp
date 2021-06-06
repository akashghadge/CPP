/*
Chef is planning a heist in the reserve bank of Chefland. They are planning to hijack the bank for D days and print the money. The initial rate of printing the currency is P dollars per day and they increase the production by Q dollars after every interval of d days. For example, after d days the rate is P+Q dollars per day, and after 2d days the rate is P+2Q dollars per day, and so on. Output the amount of money they will be able to print in the given period.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, four integers D,d,P,Q.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤105
1≤d≤D≤106
1≤P,Q≤106
Subtasks
Subtask #1 (15 points): d≤D≤100
Subtask #2 (85 points): original constraints

Sample Input
3
2 1 1 1
3 2 1 1
5 2 1 2
Sample Output
3
4
13
Explanation
Test Case 1:

On the first day, the rate of production is 1 dollar per day so 1 dollar is printed on the first day.
On the second day, the rate of production is 1+1=2 dollars per day so 2 dollars are printed on the second day.
The total amount of money printed in 2 days is 1+2=3 dollars.
Test Case 2:

For the first two days, the rate of production is 1 dollar per day so 1⋅2=2 dollars are printed on the first two days.
On the third day, the rate of production is 1+1=2 dollars per day so 2 dollars are printed on the third day.
The total amount of money printed in 3 days is 2+2=4 dollars.
Test Case 3:

For the first two days, the rate of production is 1 dollar per day so 1⋅2=2 dollars are printed on the first two days.
On the next two days, the rate of production is 1+2=3 dollars per day so 3⋅2=6 dollars are printed on the next two days.
On the last day, the rate of production is 3+2=5 dollars per day so 5 dollars are printed on the last day.
The total amount of money printed in 5 days is 2+6+5=13 dollars.
Author:	daanish_adm
Date Added:	17-05-2021
Time Limit:	0.5 secs
Source Limit:	50000 Bytes
Languages:	CPP14, C, JAVA, PYTH 3.6, PYTH, CS2, ADA, PYPY, PYP3, TEXT, CPP17, PAS fpc, RUBY, PHP, NODEJS, GO, TCL, HASK, PERL, SCALA, kotlin, BASH, JS, PAS gpc, BF, LISP sbcl, CLOJ, LUA, D, R, CAML, rust, ASM, FORT, FS, LISP clisp, SQL, swift, SCM guile, PERL6, CLPS, WSPC, ERL, ICK, NICE, PRLG, ICON, PIKE, COB, SCM chicken, SCM qobi, ST, NEM, SQLQ
*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
long long TotalDay, interval, startM, increment;
// long long totalMoney()
// {
//     // for inital days where no increment are there
//     long long withoutInc = 1LL * interval * startM;
//     TotalDay -= interval;
//     // incremented period
//     long long withInc1 = 0;
//     long long currInc = increment;
//     while (interval < TotalDay)
//     {
//         withInc1 += (startM + currInc) * 1LL * interval;
//         currInc += increment;
//         TotalDay -= interval;
//     }

//     long long remMoney = max(0LL, (TotalDay * (startM + currInc)));
//     return (withoutInc + withInc1 + remMoney);
// }
long long totalMoney()
{
    long long TotalDayOriginal = TotalDay;
    TotalDay -= interval;
    long long peroid = TotalDay / interval;
    long long remDays = TotalDay % interval;

    // go for amount 1
    long long sumOfAllPeriod = 1LL * (peroid * (peroid + 1)) / 2;
    long long amountInPeriod = sumOfAllPeriod * interval * increment;
    // cout << "Period :" << amountInPeriod << endl;

    // for rem days
    long long sumForRemDays = 1LL * remDays * increment * (peroid + 1);
    // cout << "rem :" << sumForRemDays << endl;

    long long output = amountInPeriod + sumForRemDays + (TotalDayOriginal * startM);

    return output;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> TotalDay >> interval >> startM >> increment;
        cout << totalMoney() << en;
    }
    return 0;
}
