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
vector<int> wave(vector<vector<int>> m)
{
    vector<int> ans;
    int maxR = m.size() - 1;
    int maxC = m[0].size() - 1;
    int minR = 0;
    int minC = 0;
    while (minC != maxC + 1)
    {
        cout << "Hello" << endl;
        for (int i = minR; i <= maxR; i++)
        {
            ans.push_back(m[i][minC]);
        }
        // printVector(ans);
        minC++;
        for (int i = maxR; i >= minR; i--)
        {
            ans.push_back(m[i][minC]);
        }
        minC++;
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

    vector<int> ans = wave(m);
    printVector(ans);
}