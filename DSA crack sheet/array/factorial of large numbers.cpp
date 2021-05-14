#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        cout << vec[i];
    }
    cout << endl;
}
int mult(int val, vector<int> &res)
{
    int carry = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int prod = (res[i] * val) + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
        // res_size++;
    }
    // return res_size;
}

vector<int> fact(int num)
{
    vector<int> res;
    // int res_size = 1;
    // res[0] = 1;
    res.push_back(1);
    for (int i = 2; i <= num; i++)
    {
        mult(i, res);
    }
    printVector(res);
    return res;
}
/*
    int mult(int val, vector<int> &res)
    {
        int carry = 0;
        for (int i = 0; i < res.size(); i++)
        {
            int prod = (res[i] * val) + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry)
        {
            res.push_back(carry % 10);
            carry /= 10;
            // res_size++;
        }
        // return res_size;
    }
    vector<int> factorial(int num){
        // code here
        vector<int> res;
        // int res_size = 1;
        // res[0] = 1;
        res.push_back(1);
        for (int i = 2; i <= num; i++)
        {
            mult(i, res);
        }
        // printVector(res);
        reverse(res.begin(),res.end());
        return res;
    }
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    fact(num);
    return 0;
}