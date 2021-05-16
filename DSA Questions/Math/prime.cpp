// 2<=Num<100
// 1<=T<=10
// this is  implementation of seive of eroth
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<bool> prime(MAX, true);
bool init()
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        for (int j = i + i; j < MAX; j += i)
        {
            prime[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        cout << prime[num] << endl;
    }

    return 0;
}