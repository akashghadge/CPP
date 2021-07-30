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
class Stack
{
private:
    int sizeS;
    T *st;
    int ptr = -1;
    int maxSize;

public:
    Stack(int maxSize)
    {
        st = new T[maxSize];
        sizeS = 0;
        int ptr = -1;
        this->maxSize = maxSize;
    }
    int size()
    {
        return sizeS;
    }
    bool push(T val)
    {
        if (maxSize == sizeS)
            return false;

        ptr++;
        sizeS++;
        st[ptr] = val;
        return true;
    }
    bool pop()
    {
        if (ptr == -1)
            return false;

        ptr--;
        sizeS--;
        return true;
    }
    bool empty()
    {
        return (ptr == -1) ? true : false;
    }
    T top()
    {
        if (ptr == -1)
            return -1;
        return st[ptr];
    }
};
int main()
{
    FAST;
    Stack<int> st(100);
    cout << "size : " << st.size() << en;
    for (int i = 0; i < 100; i++)
    {
        st.push(i);
    }
    cout << st.push(100) << " another push effort" << en;
    cout << "size : " << st.size() << en;
    while (!st.empty())
    {
        cout << st.top() << en;
        st.pop();
    }
    cout << "size : " << st.size() << en;

    return 0;
}