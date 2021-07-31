#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
template <class T>
class Queue
{
private:
    T *arr;
    int sizeQ;
    int maxSize;
    int frt;
    int rear;

public:
    Queue(int maxSize)
    {
        arr = new T[maxSize];
        sizeQ = 0;
        this->maxSize = maxSize;
        frt = -1;
        rear = -1;
    }
    Queue()
    {
        Queue(10);
    }
    int size()
    {
        return sizeQ;
    }
    bool empty()
    {
        return (sizeQ == 0) ? true : false;
    }
    bool push(T val)
    {
        if (frt == rear && frt == -1)
        {
            frt = 0;
            rear = 0;
            arr[rear] = val;
            sizeQ++;
            return true;
        }
        else if (frt == (rear + 1) % maxSize)
        {
            return false;
        }
        else
        {
            rear = (rear + 1) % maxSize;
            arr[rear] = val;
            sizeQ++;
            return true;
        }
        return false;
    }
    bool pop()
    {
        if (frt == rear && frt == -1)
        {
            return false;
        }
        else if (rear == frt)
        {
            rear = -1;
            frt = -1;
            sizeQ--;
        }
        else
        {
            frt = (frt + 1) % maxSize;
            sizeQ--;
        }
    }
    T front()
    {
        return arr[frt];
    }
    T back()
    {
        return arr[rear];
    }
};
int main()
{
    FAST;
    queue<int> q;
    Queue<int> Q(10);
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
        Q.push(i);
    }
    int i = 0;
    while (i < 5)
    {
        // cout << "Que STL :" << q.front() << en;
        cout << "Que Custom:" << Q.front() << en;
        // cout << "Que STL :" << q.back() << en;
        // cout << "Que Custom:" << Q.back() << en;
        q.pop();
        Q.pop();
        i++;
    }
    for (int i = 0; i < 5; i++)
    {
        q.push(i);
        Q.push(i);
    }
    i = 0;
    while (!Q.empty())
    {
        // cout << "Que STL :" << q.front() << en;
        cout << "Que Custom:" << Q.front() << en;
        // cout << "Que STL :" << q.back() << en;
        // cout << "Que Custom:" << Q.back() << en;
        q.pop();
        Q.pop();
        i++;
    }
}