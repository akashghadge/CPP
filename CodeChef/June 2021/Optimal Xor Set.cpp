/*
Find K distinct numbers in the range [1,N] such that the bitwise XOR of all the numbers is maximized. Print any set of these numbers that maximize the XOR.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two integers N, K.
Output
For each test case, output K distinct integers in any order as described in the problem.

Constraints
1≤T≤104
1≤K≤N≤106
The sum of N over all queries is at most 4⋅106.
The sum of K over all queries is at most 2⋅106.
Subtasks
Subtask #1 (5 points):

1≤T≤50
1≤K≤N≤20
Subtask #2 (20 points):

1≤T≤50
1≤K≤N≤200
The sum of N over all queries is at most 800.
The sum of K over all queries is at most 400.
Subtask #3 (75 points): original constraints

Sample Input
3
10 1
9 2
8 7
Sample Output
10
7 8
1 2 3 4 5 6 8
Explanation
Test Case 1: The only possible set is {10} which gives the value 10.

Test Case 2: The other possible set is {9,6} which gives the value 9⊕6=15=7⊕8.

Test Case 3: The only possible set is {1,2,3,4,5,6,8} which gives the value 1⊕2⊕3⊕4⊕5⊕6⊕8=15.


*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
int N, K;
vector<int> init(int N)
{
    vector<int> mainSet(N);
    for (int i = 0; i < N; i++)
    {
        mainSet[i] = i + 1;
    }
    return mainSet;
}
vector<vector<int>> subset(vector<int> &mainSet, int K)
{
    vector<vector<int>> res;
    int subset_size = pow(2, mainSet.size());
    for (int i = 0; i < subset_size; i++)
    {
        int temp = i;
        int index = 0;
        vector<int> sub;
        while (temp)
        {
            int isOn = (1 & temp);
            temp = temp >> 1;
            if (isOn)
            {
                sub.push_back(mainSet[index]);
            }
            index++;
        }
        if (sub.size() != K)
            continue;
        res.push_back(sub);
    }
    return res;
}
vector<int> solution(vector<vector<int>> &allSubset, int K)
{
    int maxXor = 0;
    vector<int> res;
    for (int i = 0; i < allSubset.size(); i++)
    {
        if (allSubset[i].size() != K)
            continue;
        int currXor = 0;
        for (int j = 0; j < allSubset[i].size(); j++)
        {
            currXor ^= allSubset[i][j];
        }
        if (currXor > maxXor)
        {
            maxXor = currXor;
            res.clear();
            res = allSubset[i];
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        if (K == 1)
        {
            cout << N << en;
            continue;
        }
        vector<int> mainSet = init(N);
        vector<vector<int>> allSubset = subset(mainSet, K);
        vector<int> res = solution(allSubset, K);
        for (auto val : res)
        {
            cout << val << " ";
        }
        cout << en;
    }

    return 0;
}