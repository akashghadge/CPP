#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#include <chrono>
using namespace std ::chrono;
void rec(int num)
{
    if (num == 1e6)
    {
        return;
    }
    int arr[100000];
    rec(num + 1);
}
int main()
{
    FAST;
    auto startTime = high_resolution_clock::now();
    rec(1);
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    float finalDur = duration.count();
    float sec = finalDur / 1000000;
    cout << "Time taken :" << sec << " sec" << endl;
    return 0;
}