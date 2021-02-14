#include <iostream>
using namespace std;
#include <queue>
int main()
{
    queue<int> queueSample;
    queueSample.push(1);
    queueSample.push(2);
    queueSample.push(3);
    queueSample.push(4);

    cout << queueSample.front() << endl;
    cout << queueSample.back() << endl;

    queueSample.emplace(5);

    cout << "Size of queue :" << queueSample.size() << endl;

    while (!queueSample.empty())
    {
        cout << "Queue element :" << queueSample.front() << endl;
        queueSample.pop();
    }
    cout << "Size of queue :" << queueSample.size() << endl;
}