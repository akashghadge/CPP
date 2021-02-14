#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// for time comp
#include <chrono>
using namespace std::chrono;

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
    auto startTime = high_resolution_clock::now();
    vector<int>
        vec;
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

    cout << vec.size() << endl;
    //here size is actuall vector size to store data and capacity is value of memory which allocate of whole vector in insertion purpose esasier i.e. greater than vector size or equal to it

    cout << vec.capacity() << "  " << vec.size() << endl;
    // it will shrink capacity of vector to size for avoiding exatra space
    vec.shrink_to_fit();
    cout << vec.capacity() << "  " << vec.size() << endl;

    // therotical size limit of vec
    // cout << vec.max_size() << endl;
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << duration.count() << endl;
}