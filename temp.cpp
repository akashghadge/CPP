#include <bits/stdc++.h>
#define en "\n"
#define ll long long
#include <chrono>
using namespace std ::chrono;
using namespace std;
int main()
{
    auto startTime = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*code here*/
    int N = 1e7;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
    {
        vec[i] = i;
    }

    /*code here*/
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    float finalDur = duration.count();
    float sec = finalDur / 1000;
    cout << "Time taken :" << sec << " sec" << endl;
}