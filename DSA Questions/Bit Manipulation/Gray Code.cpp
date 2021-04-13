#include <iostream>
using namespace std;
#include "vector"
// basiclly gray code is code which adjusant numbers only differ by 1 bit
// so consider
/*
00
01
11
10
here we notice 
first bit is same as binary number i.e half zero half 1
and remaining bits (from second bit) are lower half is mirror of upper half 
so every time we have if we have 2^3 to calculate we can easily get this from the 2^2 i.c recursion
*/
vector<string> graycode(int n)
{
    // base case for gray code
    if (n == 1)
    {
        vector<string> res;
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    vector<string> preAns = graycode(n - 1);
    vector<string> ans;
    for (auto val : preAns)
    {
        ans.push_back("0" + val);
    }
    for (int i = preAns.size() - 1; i >= 0; i--)
    {
        ans.push_back("1" + preAns[i]);
    }
    return ans;
}
void printVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    printVector(ans);
}