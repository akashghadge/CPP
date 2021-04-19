#include <iostream>
using namespace std;
#include <unordered_set>

int sub(int *arr, int N)
{
    unordered_set<int> S;
    int ans = 0;

    for (int i = 0; i < N; i++)
        S.insert(arr[i]);

    for (int i = 0; i < N; i++)
    {
        if (S.find(arr[i] - 1) == S.end())
        {

            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}
int main()
{
    int N = 7;
    int a[] = {1,
               9,
               3,
               10,
               4,
               20,
               2};
    int result = sub(a, N);
    cout << result;
}