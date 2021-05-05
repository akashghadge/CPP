#include <iostream>
using namespace std;
#include <vector>
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
vector<int> spiral(vector<vector<int>> m)
{
    vector<int> ans;
    int minC = 0;
    int minR = 0;
    int maxR = m.size();
    int maxC = m[0].size();
    int tnp = maxC * maxR;

    while (ans.size() < tnp)
    {
        for (int i = minR; i < maxR; i++)
        {
            ans.push_back(m[i][minC]);
        }
        minC++;
        for (int i = minC; i < maxC; i++)
        {
            ans.push_back(m[maxR - 1][i]);
        }
        maxR--;
        for (int i = maxR - 1; i >= minR; i--)
        {
            ans.push_back(m[i][maxC - 1]);
        }
        maxC--;
        cout << minC << " " << maxC << endl;
        for (int i = maxC - 1; i >= minC; i--)
        {
            // printVector(ans);
            ans.push_back(m[minR][i]);
        }
        minR++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 13},
        {4, 5, 6, 14},
        {7, 8, 9, 15},
        {10, 11, 12, 16}};

    vector<int> ans = spiral(m);
    printVector(ans);
}