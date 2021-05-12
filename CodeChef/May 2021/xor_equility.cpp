#include <iostream>
using namespace std;
long long power(long long y, long long x = 2)
{
    long long res = 1; // Initialize result
    long long M = 1e9 + 7;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = ((res % M) * (x % M)) % M;

        // n must be even  now
        y = y >> 1;                  // y = y/2
        x = ((x % M) * (x % M)) % M; // Change x to x^2
    }
    return res;
}
int main()
{
    long long M = 1e9 + 7;
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        long long total = 1;
        for (long long i = 0; i < N - 1; i++)
        {
            total = ((total % M) * (2)) % M;
        }
        cout << total << "\n";
        cout << power(N - 1);
    }
}