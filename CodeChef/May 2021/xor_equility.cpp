#include <iostream>
using namespace std;

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
            cout << total << endl;
            total = ((total % M) * (2)) % M;
        }
        cout << total;
    }
}