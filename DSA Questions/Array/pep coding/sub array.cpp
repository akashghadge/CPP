//  abc have a,ab,abc,b,bc,c
#include <iostream>
using namespace std;
#include <vector>
void printVec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int util(int *arr, int size, int index, vector<vector<int>> &ans, vector<int> curr)
{
    // cout << "helllo" << endl;
    if (index >= size)
    {
        if (curr.size() != 0)
        {
            // printVec(curr);
            ans.push_back(curr);
        }
        return 0;
    }
    util(arr, size, index + 1, ans, curr);
    curr.push_back(arr[index]);
    util(arr, size, index + 1, ans, curr);
}
void printVector(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto val : vec[i])
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
int subArray(int *arr, int size)
{
    vector<vector<int>> ans;
    vector<int> curr;
    util(arr, size, 0, ans, curr);
    printVector(ans);
}
int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    subArray(arr, size);
}