#include <iostream>
using namespace std;
#include <vector>
int getSolubility(int x, int a, int b)
{
    int res = a + (100 - x) * b;
    return res;
}
int main()
{
    int T;
    cin >> T;
    vector<int> output;
    int j = 0;
    while (T--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        j++;
        int solubility = getSolubility(x, a, b);
        solubility *= 10;
        output.push_back(solubility);
    }
    for (auto val : output)
    {
        cout << val << endl;
    }
}