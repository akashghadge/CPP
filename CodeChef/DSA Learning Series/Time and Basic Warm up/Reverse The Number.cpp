/*
Given an Integer N, write a program to reverse it.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, display the reverse of the given number N, in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
4
12345
31203
2123
2300
Output
54321
30213
3212
32

*/

#include <bits/stdc++.h>
using namespace std;
int rev(int num)
{
    stack<int> st;
    while (num)
    {
        st.push(num % 10);
        num /= 10;
    }
    int i = 1;
    while (!st.empty())
    {
        num += (st.top() * i);
        st.pop();
        i *= 10;
    }
    return num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int num;
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        cout << rev(num) << endl;
    }

    return 0;
}