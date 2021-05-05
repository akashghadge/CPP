#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
vector<int> getOneD(vector<vector<int>> m, int shellNo)
{
    vector<int> ans;
    int minR = shellNo - 1;
    int minC = shellNo - 1;
    int maxC = m.size() - shellNo;
    int maxR = m.size() - shellNo;
    for (int i = minR; i <= maxR; i++)
    {
        ans.push_back(m[i][minC]);
    }
    minC++;
    printVector(ans);
    for (int i = minC; i <= maxC; i++)
    {
        ans.push_back(m[maxR][i]);
    }
    maxR--;
    for (int i = maxR; i >= minR; i--)
    {
        ans.push_back(m[i][maxC]);
    }
    maxC--;
    for (int i = maxC; i >= minC; i--)
    {
        ans.push_back(m[minR][i]);
    }
    return ans;
}
void rotateOneD(vector<int> &oneD, int rotateN)
{
    rotateN = rotateN % oneD.size();
    if (rotateN < -1)
    {
        rotateN += oneD.size();
    }

    reverse(oneD.begin(), oneD.begin() + oneD.size() - rotateN - 1);
    reverse(oneD.begin() + oneD.size() - rotateN, oneD.begin() + oneD.size() - 1);
    reverse(oneD.begin(), oneD.end());
}
void fillShell(vector<vector<int>> m, int shellNo, vector<int> oneD)
{
}
void shellRotate(vector<vector<int>> m, int shellNo, int rotateN)
{
    vector<int> oneD = getOneD(m, shellNo); //array,shell number
    printVector(oneD);
    // printVector(oneD);
    rotateOneD(oneD, rotateN);
    printVector(oneD);
    fillShell(m, shellNo, oneD);
}
int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 13},
        {4, 5, 6, 14},
        {7, 8, 9, 15},
        {10, 11, 12, 16}};

    shellRotate(m, 1, 2);
}