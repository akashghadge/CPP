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
int multiply(int x, int *res, int res_size)
{
    int carray = 0;
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carray;
        res[i] = prod % 10;
        carray = prod / 10;
    }
    while (carray)
    {
        res[res_size] = carray % 10;
        carray /= 10;
        res_size++;
    }
    return res_size;
}
int *fact(int num)
{
    int res[500];
    res[0] = 1;
    int res_size = 1;
    for (int i = 2; i <= num; i++)
    {
        res_size = multiply(i, res, res_size);
    }
    for (int i = res_size - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}
int main()
{
    fact(100);
}