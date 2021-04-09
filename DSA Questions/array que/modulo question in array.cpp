#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int N;
    int K;
    int pairs = 0;
    while (t--)
    {
        cin >> N;
        cin >> K;
        int arr[N];
        int i;
        for (i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        for (i = 0; i < N; i++)
        {
            cout << "THE VALUE AT " << i << " INDEX IS " << arr[i] << endl;
        }
        i = 0;
        int j = i + 1;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (i != j)
                {
                    if (arr[i] % arr[j] == K)
                    {
                        pairs++;
                    }
                }
            }
        }
        cout << pairs;
    }
}