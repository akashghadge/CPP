#include <iostream>
using namespace std;
#include "vector"
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
    vector<int> vec = {1, 3, 6, 2, 8, 5, 7};
    printVector(vec);
    
}