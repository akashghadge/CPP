/*

*/

// Given two arrays, check if one array is
// stack permutation of other.
#include <bits/stdc++.h>
using namespace std;

// function to check if input queue is
// permutable to output queue
bool checkStackPermutation(int ip[], int op[], int n)
{
    queue<int> inp;
    queue<int> otp;
    for (int i = 0; i < n; i++)
    {
        inp.push(ip[i]);
        otp.push(op[i]);
    }
    stack<int> temp;
    while (inp.size())
    {
        int t1 = inp.front();
        inp.pop();
        if (t1 == otp.front())
        {
            otp.pop();
        }
        else if (!temp.empty() && temp.top() == otp.front())
        {
            temp.pop();
            otp.pop();
        }
        else
        {
            temp.push(t1);
        }
    }
    return (temp.empty() && inp.empty());
}

// Driver program to test above function
int main()
{
    // Input Queue
    int input[] = {1, 2, 3};

    // Output Queue
    int output[] = {2, 1, 3};

    int n = 3;

    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
