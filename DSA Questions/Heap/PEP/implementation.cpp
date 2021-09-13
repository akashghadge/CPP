#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class PriorityQueue
{
private:
    /* data */
    vector<int> heap;

public:
    PriorityQueue() {}
    int upHepify(int index)
    {
        if (index == 0)
            return 0;
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] > heap[index])
        {
            swap(heap[parentIndex], heap[index]);
            upHepify(parentIndex);
        }
        else
        {
            return 0;
        }
    }
    int downHepify(int index)
    {
        int mini = index;
        int leftIndex = (2 * index) + 1;
        int rightIndex = (2 * index) + 2;
        if (leftIndex < heap.size() && heap[leftIndex] < heap[mini])
        {
            mini = leftIndex;
        }
        if (rightIndex < heap.size() && heap[rightIndex] < heap[mini])
        {
            mini = rightIndex;
        }
        if (index != mini)
        {
            swap(heap[index], heap[mini]);
            downHepify(mini);
        }
    }
    void push(int val)
    {
        heap.push_back(val);
        upHepify(heap.size() - 1);
    }
    int peek()
    {
        return heap.size() ? heap[0] : -1;
    }
    int pop()
    {
        int val = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        downHepify(0);
        return val;
    }
    int size()
    {
        return heap.size();
    }
    void print()
    {
        for (auto val : heap)
        {
            cout << val << " ";
        }
        cout << en;
    }
};

int main()
{
    FAST;
    PriorityQueue qc;
    priority_queue<int> q;
    for (int i = 0; i < 5; i++)
    {
        qc.push(i);
        q.push(i);
    }
    cout << "size: " << q.size() << " " << qc.size() << en;
    while (qc.size() && q.size())
    {
        cout << q.top() << " " << qc.peek() << en;
        q.pop();
        qc.pop();
    }

    cout << "size: " << q.size() << " " << qc.size() << en;
    return 0;
}