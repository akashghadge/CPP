#include <iostream>
using namespace std;
bool isLand(long long N, long long x, long long k)
{
    if (x >= k && x % k == 0)
    {
        return true;
    }

    if ((N - x) >= k && (N - x) % k == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long N, x, k;
        cin >> N >> x >> k;
        isLand(N + 1, x, k) ? cout << "YES" << endl : cout << "NO" << endl;
    }
}
