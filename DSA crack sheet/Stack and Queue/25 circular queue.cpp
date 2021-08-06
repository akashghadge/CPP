/*
Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’. 
 

circularqueues

 
In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.
 

Operations-on-Circular queue

Operations on Circular Queue: 
 



Front: Get the front item from queue.
Rear: Get the last item from queue.
enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position. 
Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).
If it is full then display Queue is full. If queue is not full then, check if (rear == SIZE – 1 && front != 0) if it is true then set rear=0 and insert element.
deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position. 
Check whether queue is Empty means check (front==-1).
If it is empty then display Queue is empty. If queue is not empty then step 3
Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set front=0 and return the element.

*/

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