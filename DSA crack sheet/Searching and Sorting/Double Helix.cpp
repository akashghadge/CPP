/*
Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.

Output
For each test case, write on a separate line, the largest possible sum that can be produced.

Sample
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const int N = 1e5 + 7;
vi seq1(N);
vi seq2(N);
int n1, n2;
int sol()
{
    unordered_map<int, int> isDuplicate;
    unordered_map<int, int> prfixSum;
    for (int i = 0; i < n1; i++)
    {
        isDuplicate[seq1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (isDuplicate.find(seq2[i]) == isDuplicate.end())
            continue;
        prfixSum[seq2[i]] = 0;
    }
    int sum1 = 0;
    for (int i = 0; i < n1; i++)
    {
        sum1 += seq1[i];
        if (prfixSum.find(seq1[i]) != prfixSum.end())
        {
            prfixSum[seq1[i]] = sum1;
            sum1 = 0;
        }
    }
    int sum2 = 0;
    for (int i = 0; i < n2; i++)
    {
        sum2 += seq2[i];
        if (prfixSum.find(seq2[i]) != prfixSum.end())
        {
            prfixSum[seq2[i]] = max(prfixSum[seq2[i]], sum2);
            sum2 = 0;
        }
    }

    int totalAns = 0;
    totalAns += max(sum1, sum2);
    for (auto val : prfixSum)
    {
        totalAns += val.second;
    }
    return totalAns;
}
int main()
{
    FAST;
    while (true)
    {
        cin >> n1;
        if (n1 == 0)
            break;
        for (int i = 0; i < n1; i++)
        {
            cin >> seq1[i];
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> seq2[i];
        }
        cout << sol() << en;
    }

    return 0;
}