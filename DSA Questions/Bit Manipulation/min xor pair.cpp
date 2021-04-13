#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
// you can done it easily in o(n^2) using two loop and getting all pair compare
// now firslty sort all elements and then so if after sorting a,b,c,d,e then here a<b<c so a^b & b^c is always min than a^c
// so we only compare adjusant elements
void sol(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    int minVal = INT8_MAX;
    vector<string> ans;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int XOR = vec[i] ^ vec[i + 1];
        if (minVal > XOR)
        {
            minVal = vec[i] ^ vec[i + 1];
            ans.clear();
            string temp = to_string(vec[i]) + " " + to_string(vec[i + 1]);
            ans.push_back(temp);
        }
        else if (minVal == XOR)
        {
            string temp = to_string(vec[i]) + " " + to_string(vec[i + 1]);
            ans.push_back(temp);
            // printf("hello");
        }
    }
    for (auto val : ans)
    {
        cout << val << endl;
    }
}
int main()
{
    int size;
    cin >> size;
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
    sol(vec);
}