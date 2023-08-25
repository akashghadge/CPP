/*
Always think like multiply and normalize numbers
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> factorial(int n)
{
    // code here
    vector<int> res(1, 1);
    for (int num = 2; num <= n; num++)
    {
        // multipy operation
        for (int i = 0; i < res.size(); i++)
            res[i] *= num;

        // normalization
        int carry = 0;
        for (int i = 0; i < res.size(); i++)
        {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        while (carry)
        {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
}