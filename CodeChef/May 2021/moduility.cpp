#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int ct = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if ((M % i) % j == (M % j) % i)
                {
                    ct++;
                }
            }
        }
        cout << ct << "\n";
    }
}
