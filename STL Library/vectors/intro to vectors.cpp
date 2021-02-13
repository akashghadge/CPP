#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void displayVec(vector<int>::iterator start, vector<int>::iterator end)
{
    while (start != end)
    {
        cout << "element : " << *start << endl;
        start++;
    }
    cout << endl;
}
int main()
{
    vector<int> vec;
    vector<int>::iterator start;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    start = vec.begin();

    displayVec(vec.begin(), vec.end());

    vector<int>::iterator itr;
    cout << vec.size() << endl;

    // inserting element in vector
    vec.insert(start, 500);
    displayVec(vec.begin(), vec.end());

    // inserting more copy on the vector
    vec.insert(start + 1, 5, 5);
    displayVec(vec.begin(), vec.end());

    //getting last value of vector
    int valueAtLast = vec.back();
    // cout << &valueAtLast << endl;

    //getting basically value can vector hold before allocating exatra memory
    int capVec = vec.capacity();
    // cout << capVec << endl;

    // vec.cbegin() and vec.cend() is same as ordinary start

    // it will clear interanal elements but memory free is task fo user
    // vec.clear();
    // displayVec(start, vec.end());

    vec.erase(start);

    cout << vec.data() << endl;    //retrun pointer of first element
    cout << &(vec.back()) << endl; //return last element value

    cout << &(vec.front());

    vec.reserve(5); //allocate memory previously
    displayVec(start, vec.end());

    cout << vec.size();
}