#include <iostream>
using namespace std;
#include "vector"
// firstly make xor array of a[i]^a[i+1]
// then second array contains all zeros
vector<vector<int>> xorZero(vector<int> n)
{
    vector<vector<int>> ans;
    for (int i = 0; i < n.size() - 1; i++)
    {
        n[i] ^= n[i + 1];
    }
    vector<int> ansTemp(n.size(), 0);
    ans.push_back(n);
    ans.push_back(ansTemp);
    return ans;
}
void printVector(vector<vector<int>> vec)
{
    for (auto itr : vec)
    {
        for (int i = 0; i < itr.size(); i++)
        {
            cout << "At Index " << i << " Vector have : " << itr[i] << endl;
        }
        cout << endl;
    }
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    printVector(xorZero(vec));
}