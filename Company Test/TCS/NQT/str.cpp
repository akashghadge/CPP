#include <bits/stdc++.h>
using namespace std;
#define en "\n"
int sol(int N, int L, string str)
{
    queue<char> q;
    int ptr = L;
    int ans = 0;
    for (int i = 0; i < L; i++)
    {
        q.push(str[i]);
    }

    while (ptr < N)
    {
        queue<char> temp = q;
        temp.pop();
        temp.push(str[ptr]);
        queue<char> next = temp;
        while (!temp.empty())
        {
            if (temp.front() != q.front())
                ans++;
            temp.pop();
            q.pop();
        }
        q = next;
        ptr++;
    }

    return ans;
}
int main()
{
    int N, L;
    string str;
    cin >> N >> L >> str;
    cout << sol(N, L, str) << en;
    return 0;
}