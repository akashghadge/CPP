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

vector<int> ceilAndFloor(int *arr, int size, int element)
{
    vector<int> ans;
    int low = 0;
    int high = size - 1;
    while (high > low)
    {
        if (arr[low] <= element)
        {
            low++;
        }
        if (arr[high] >= element)
        {
            high--;
        }
    }
    ans.push_back(low);
    ans.push_back(high + 1);
    return ans;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 15;
    vector<int> ans = ceilAndFloor(arr, size, element);
    printVector(ans);
}