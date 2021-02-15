#include <iostream>
using namespace std;
#include "algorithm"
#include "functional"
#include "vector"

int main()
{
    vector<int> v;
    v.push_back(50);
    v.push_back(20);
    v.push_back(60);
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);

    vector<int>::iterator itr;
    itr = v.begin();

    sort(itr, v.end());

    // here greater<int>() is functors
    sort(itr, v.end(), greater<int>());
    sort(itr, v.end(), less<int>());
    // this will throw the error
    // sort(itr, v.end(), __or_<int>());
    while (itr != v.end())
    {
        cout << "Element of Vector :" << *itr << endl;
        itr++;
    }
}