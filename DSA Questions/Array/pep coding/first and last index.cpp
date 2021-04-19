// here we need to give first and last index of element in sorted array
// use binary serch compulsory

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
int util(int *arr, int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] > target)
    {
        return util(arr, start, mid - 1, target);
    }
    else
    {
        return util(arr, mid + 1, end, target);
    }
}
vector<int> firstAndLast(int *arr, int size, int element)
{
    int index = util(arr, 0, size, element);
    int firstIndex = index;
    int lastIndex = index;
    int i = 1;
    while (arr[index] == arr[index + i] || arr[index] == arr[index - i])
    {
        if (arr[index] == arr[index + i])
        {
            lastIndex++;
        }
        if (arr[index] == arr[index - i])
        {
            firstIndex--;
        }
        i++;
    }
    cout << "itrations " << i << endl;
    vector<int> ans;
    ans.push_back(firstIndex);
    ans.push_back(lastIndex);
    return ans;
}
int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30, 40, 50, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 30;
    vector<int> ans = firstAndLast(arr, size, element);
    printVector(ans);
}