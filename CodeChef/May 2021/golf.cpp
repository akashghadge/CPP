#include <iostream>
using namespace std;
bool isLand(int N, int x, int k)
{
    for (int i = 0; i <= N; i += k)
    {
        if (i == x)
        {
            return true;
        }
    }
    for (int i = N; i >= 0; i -= k)
    {
        if (i == x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, x, k;
        scanf("%d %d %d", &N, &x, &k);
        isLand(N + 1, x, k) ? cout << "TRUE" << endl : cout << "NO" << endl;
    }
}