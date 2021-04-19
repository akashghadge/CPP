#include <iostream>
using namespace std;
#include <vector>
// it is dp question and will get solved with basic array approch
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int maxProfit(int *arr, int size)
{
}
int main()
{
    int arr[] = {2, 87, 45, 7, 37};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, size);
}