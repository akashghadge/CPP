#include <iostream>
using namespace std;
#include <vector>
vector<int> exitP(vector<vector<int>> m)
{
    vector<int> ans;
    int dir = 0; //0->e 1-> s 2-> w 3->n
    int i = 0, j = 0;
    while (true)
    {
        if (m[i][j] == 1)
        {
            dir++;
        }
        dir = dir % m.size();
        if (dir == 0)
        {
            j++;
        }
        else if (dir == 1)
        {
            i++;
        }
        else if (dir == 2)
        {
            j--;
        }
        else if (dir == 3)
        {
            i--;
        }

        // boundary codition
        if (i < 0)
        {
            i++;
            break;
        }
        else if (j < 0)
        {
            j++;
            break;
        }
        else if (i == m.size())
        {
            i--;
            break;
        }
        else if (j == m[0].size())
        {
            j--;
            break;
        }
    }
    ans.push_back(i);
    ans.push_back(j);
    return ans;
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector<vector<int>> m = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 1, 0}};
    vector<int> ans = exitP(m);
    printVector(ans);
}