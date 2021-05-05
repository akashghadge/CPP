#include <iostream>
using namespace std;
#include <vector>

vector<int> search(vector<vector<int>> m, int target)
{
    vector<int> ans(2, -1);
    if (m.size() == 0)
    {
        return ans;
    }

    int n = m.size();
    int i = 0, j = m[0].size() - 1;
    while (i < m.size() || j >= 0)
    {
        if (m[i][j] == target)
        {
            ans[0] = i;
            ans[1] = j;
            return ans;
        }
        else if (m[i][j] > target)
        {
            j--;
        }
        else if (m[i][j] < target)
        {
            i++;
        }
    }
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    vector<int> ans = search(m, 1);
    printVector(ans);
}