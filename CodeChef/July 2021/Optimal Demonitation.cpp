/*
You are the owner of a big company. You are so rich, that the government has allowed you to print as many notes as you want of any single value that you like. You also have peculiar behavioral traits and you often do things that look weird to a third person.

You have N employees, where the i-th employee has salary Ai. You want to pay them using a denomination that you create. You are also eco-friendly and wish to save paper. So, you wish to pay them using as few notes as possible. Find out the minimum number of notes required if you can alter the salary of at most one employee to any positive integer that you like, and choose the positive integer value that each note is worth (called its denomination).

Each employee must receive the exact value of his/her salary and no more.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N.
The second line contains N integers A1,A2,…,AN, where Ai is the salary of the i-th employee.
Output
For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤12⋅104
1≤N≤105
1≤Ai≤109
The sum of N over all test cases is at most 106.
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input
3
3
1 2 3
3
8 4 2
2
2 2 
Sample Output
4
4
2
Explanation
Test Case 1: We can change the salary of the third person to 1 and use 1 as the denomination. So in total we need 11+21+11 = 1+2+1 = 4 notes.

Test Case 2: We can change the salary of the first person to 2 and use 2 as the denomination. So in total we need 1+2+1 = 4 notes.

Test Case 3: We can use 2 as the denomination and we need not change the salary of any person. So in total we need 1+1 = 2 notes.
*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int N;
// ll sol(vector<ll> &arr)
// {
//     // firstly check the gcd of elements every time one element is elimimated
//     if (N == 1)
//     {
//         return 1;
//     }
//     ll minSalry = INT_MAX;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         ll totalGCD = 0;
//         // cout << "Value of I : " << i << en;
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if (i == j)
//                 continue;
//             totalGCD = __gcd(totalGCD, arr[j]);
//         }
//         // cout << "Total GCD : " << totalGCD << en;
//         ll amountOfTotalSalary = 0;
//         for (int j = 0; j < arr.size(); j++)
//         {
//             if (i == j)
//                 continue;
//             amountOfTotalSalary += (arr[j] / totalGCD);
//         }
//         // cout << "Total Salary : " << amountOfTotalSalary << en;
//         minSalry = min(minSalry, amountOfTotalSalary);
//     }
//     return minSalry + 1;
// }

ll solOp(vector<ll> arr)
{
    int size = arr.size();
    if (size == 1)
    {
        return 1;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    vector<ll> l(arr.size());
    vector<ll> r(arr.size());
    vector<ll> f(arr.size());
    ll gcd = 0;
    for (int i = 0; i < size; i++)
    {
        l[i] = gcd;
        gcd = __gcd(gcd, arr[i]);
    }
    gcd = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        r[i] = gcd;
        gcd = __gcd(gcd, arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        f[i] = __gcd(l[i], r[i]);
    }
    ll maxGCD = *max_element(f.begin(), f.end());
    for (int i = 0; i < size; i++)
    {
        if (maxGCD == f[i])
        {
            arr[i] = maxGCD;
            break;
        }
    }

    ll TotalSalary = 0;
    for (int i = 0; i < size; i++)
    {
        TotalSalary += (arr[i] / maxGCD);
    }
    return TotalSalary;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<ll> arr(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << solOp(arr) << en;
    }
    return 0;
}
