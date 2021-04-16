#include <iostream>
using namespace std;
// here are lots of approch there
// ussing two for loops but time is o(n^2)
// using hash map counter O(n)/O(n)
// sort array and get ajusant elments but time is reduce to o(nlogn)
// here we can use the special case of elements in array are n-1 numbers
// so we can solve this problem in o(n) and constant space
// we use current array as hash map
#include <vector>
vector<int> dup(int *arr, int size)
{
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        arr[arr[i] % size] = arr[arr[i] % size] + size;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "hello" << endl;
        if (arr[i] >= size * 2)
        {
            ans.push_back(i);
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
    int N = 5;
    int arr[] = {2,
                 3,
                 1,
                 2,
                 3};
    vector<int> ans = dup(arr, N);
    printVector(ans);
}